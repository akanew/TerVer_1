#include "terver_lab1.h"

TerVer_Lab1::TerVer_Lab1(QWidget *parent, Qt::WFlags Error_Input_Datas)
	: QMainWindow(parent, Error_Input_Datas)
{
	ui.setupUi(this);

	//Определение кодировки
	QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
	QTextCodec::setCodecForCStrings (codec);

	connect( ui.Button, SIGNAL(clicked()), this, SLOT(Open_Action()));
	connect( ui.Button_2, SIGNAL(clicked()), this, SLOT(Calculate_Action()));
	connect( ui.Create_Table, SIGNAL(clicked()), this, SLOT(Create_Table()));
	connect( ui.Create_Table_2, SIGNAL(clicked()), this, SLOT(Create_Tables()));
	connect( ui.Zoom_Button_1, SIGNAL(clicked()), this, SLOT(Zoom_Graphic_Histogram()));
	connect( ui.Zoom_Button_2, SIGNAL(clicked()), this, SLOT(Zoom_Graphic_Relative_Frequencies()));
	connect( ui.Zoom_Button_3, SIGNAL(clicked()), this, SLOT(Zoom_Graphic_Empirical_Function()));

	//Отключение полей Header-ов (Скажем "Нет!" шапке таблицы используемой по умолчанию)
	ui.Table->horizontalHeader()->hide();
	ui.Table->verticalHeader()->hide();
	ui.Table_2->horizontalHeader()->hide();
	ui.Table_2->verticalHeader()->hide();
	ui.Table_3->horizontalHeader()->hide();
	ui.Table_3->verticalHeader()->hide();

	Table_is_Full=false;

	//Вывод описания границ и характеристик
	/*ui.Table->setToolTip("Вы можете загрузить таблицу из файла используя кнопку \"Загрузить из файла\", или заполнить её самостоятельно используя кнопку \"Сформировать таблицу\"");
	ui.Table_2->setToolTip("Вы можете заполнить одну из таблиц самостоятельно используя кнопку \"Сформировать таблицу\", предварительно указав количество интервалов");
	ui.Table_3->setToolTip("Вы можете заполнить одну из таблиц самостоятельно используя кнопку \"Сформировать таблицу\", предварительно указав количество интервалов");*/
}

void TerVer_Lab1::Open_Action()
{	
	QGraphicsScene *scene;
	QTableWidgetItem *item;
	int row=0,col=0;
	QString tmp;	
	
	bool Error_Input_Data_Size=false;
	bool Error_Input_Data_Text=false;
	Fractional_Number=false;
	Minus=false;

	QString File_Name = QFileDialog::getOpenFileName( this,QString("Открыть файл"), QString(),QString("Текстовые файлы (*.txt)"));
	QFile file(File_Name);

	if(!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::information(0, "Файл с данными не был выбран!", file.errorString());
		Table_is_Full=false;
	}
	else Table_is_Full=true;

//=======================================================================================================================//
	ui.Table_Width->setValue(0);
	ui.Table_Height->setValue(0);
	ui.Table_2->setRowCount(0);//Очистка таблицы
	ui.Table_2->setColumnCount(0);//Очистка таблицы
	ui.Table_3->setRowCount(0);//Очистка таблицы
	ui.Table_3->setColumnCount(0);//Очистка таблицы
	ui.Sum->clear();
	ui.k_widget->setValue(0);
	ui.X->clear();
	ui.D->clear();
	ui.S->clear();
	ui.A->clear();
	ui.Sigma->clear();
	ui.Text_Task->clear();
	
	//Отрисовка системы координат
	scene = new QGraphicsScene(ui.Browser);   
	QPen pen(Qt::black);

	scene->clear();
	ui.Browser_3->setScene(scene);

	/*scene->addLine(-60,230,200,230,pen);//Ось X
	scene->addLine(-60,0,-60,230,pen);//Ось y
	scene->addLine(195,225,200,230,pen);//Стрелка - ось X
	scene->addLine(195,235,200,230,pen);//Стрелка - ось X
	scene->addLine(-60,0,-65,5,pen);//Стрелка - ось y
	scene->addLine(-60,0,-55,5,pen);//Стрелка - ось y
	
	QGraphicsTextItem* text;
	text = scene->addText("0", QFont("Arial", 6 ));
	text->setPos(-84,230);*/

	ui.Browser->setScene(scene);
	ui.Browser_2->setScene(scene);
	ui.Browser_4->setScene(scene);
//=======================================================================================================================//

	QTextStream in(&file);	

	ui.Table->setRowCount(0);//Очистка таблицы
	ui.Table->setColumnCount(0);//Очистка таблицы

	while(!in.atEnd()) 
	{
		QString line = in.readLine();
		
		if(line.length())
		{
			ui.Table->insertRow(row);

			for(int i=0;i<=line.length();i++)
			{
				if(line[i]==' '||i==line.length())
				{
					if(ui.Table->columnCount()<=col)
						ui.Table->insertColumn(col);

					item = new  QTableWidgetItem(tmp);
					item->setTextAlignment(Qt::AlignCenter); 
					ui.Table->setItem(row,col, item);

					tmp="";
					col++;
				}
				else 
				{
					if (line[i]=='-' || line[i]==',' || line[i]=='.' ||line[i].isNumber())
					{
						if(line[i]!=',' ) tmp+=line[i];
						else tmp+='.';
						if(line[i]=='-')
							Minus=true;
					}
					else 
						Error_Input_Data_Text=true;
				}	
			}

			if(col<ui.Table->columnCount())Error_Input_Data_Size=true;

			col=0;
			row++;
		}		
	}

	//Возврат данных в ячейки "Ширина таблицы" и "Высота таблицы"
	ui.Table_Width->setValue(ui.Table->columnCount());
	ui.Table_Height->setValue(ui.Table->rowCount());

	if(Error_Input_Data_Text && Error_Input_Data_Size)
	{
		ui.Table->setRowCount(0);//Очистка таблицы
		ui.Table->setColumnCount(0);//Очистка таблицы
		ui.Table_Width->setValue(0);
		ui.Table_Height->setValue(0);
		Table_is_Full=false;
		QMessageBox::warning(0, "Ошибка при считывании данных из файла", "Возможно в файле содержатся неверные данные.\n  Пожалуйста, попробуйте выбрать другой файл\n           или исправьте ошибки в текущем.");
	}
	else
	{
		if(Error_Input_Data_Text)QMessageBox::warning(0, "Ошибка при считывании данных из файла", "В файле с данными был найден текст, который был удален при считывании.\n           Пожалуйста, проверьте полученные данные на правильность.");
		if(Error_Input_Data_Size)QMessageBox::warning(0, "Ошибка при считывании данных из файла", "Количество данных полученных из файла не соответствуют\n                           размерности таблицы.");
	}

	file.close();
}

TerVer_Lab1::~TerVer_Lab1(){}


void TerVer_Lab1::Create_Table()
{
	ui.Table->setRowCount(0);//Очистка таблицы
	ui.Table->setColumnCount(0);//Очистка таблицы

	//Создание таблицы рядов
	ui.Table->setRowCount(ui.Table_Height->value());
	ui.Table->setColumnCount(ui.Table_Width->value());

	if(!ui.Table->rowCount() || !ui.Table->columnCount())Table_is_Full=false;
	else Table_is_Full=true;
}

void TerVer_Lab1::Create_Tables()
{
	QTableWidgetItem *item;
//=======================================================================================================================//
//================================================ Создание таблицы частот ==============================================//
//=======================================================================================================================//
	//Очистка таблицы
	ui.Table_2->setRowCount(0);
	ui.Table_2->setColumnCount(0);//Очистка таблицы

	//Создание таблицы частот
	if(ui.k_widget->value())
	{
		ui.Table_2->setRowCount(2);
		ui.Table_2->setColumnCount(ui.k_widget->value()+1);

		for(int i=1;i<ui.k_widget->value();i++)
		{
			item = new  QTableWidgetItem("[ ; )");
			item->setTextAlignment(Qt::AlignCenter);
			ui.Table_2->setItem(0,i, item);
		}
		item = new  QTableWidgetItem("[ ; ]");
		item->setTextAlignment(Qt::AlignCenter);
		ui.Table_2->setItem(0,ui.k_widget->value(), item);

		//Шапка таблицы
		item = new  QTableWidgetItem("Xi");
		item->setTextAlignment(Qt::AlignCenter);
		ui.Table_2->setItem(0,0, item);
		item = new  QTableWidgetItem("Mi");
		item->setTextAlignment(Qt::AlignCenter);
		ui.Table_2->setItem(1,0, item);
	}

//=======================================================================================================================//
//============================================== Создание таблицы частстей ==============================================//
//=======================================================================================================================//
	//Очистка таблицы
	ui.Table_3->setRowCount(0);
	ui.Table_3->setColumnCount(0);//Очистка таблицы

	//Создание таблицы частстей
	if(ui.k_widget->value())
	{
		ui.Table_3->setRowCount(2);
		ui.Table_3->setColumnCount(ui.k_widget->value()+1);

		//Вывод в  таблицу формата для представления данных т.е. [;) и [;]
		for(int i=1;i<ui.k_widget->value();i++)
		{
			item = new  QTableWidgetItem("[ ; )");
			item->setTextAlignment(Qt::AlignCenter);
			ui.Table_3->setItem(0,i, item);
		}
		item = new  QTableWidgetItem("[ ; ]");
		item->setTextAlignment(Qt::AlignCenter);
		ui.Table_3->setItem(0,ui.k_widget->value(), item);

		//Шапка таблицы
		item = new  QTableWidgetItem("Xi");
		item->setTextAlignment(Qt::AlignCenter);
		ui.Table_3->setItem(0,0, item);
		item = new  QTableWidgetItem("Wi");
		item->setTextAlignment(Qt::AlignCenter);
		ui.Table_3->setItem(1,0, item);
	}
}

void TerVer_Lab1::Calculate_Action()
{
	QTableWidgetItem *item;
	QString tmp_str,tmp_str_1,tmp_str_2,string_item;
	int count=0;
	int sum=0;
	bool ok;
	int start_point=-60;
	int finish_point=200;
	bool Error_Fill_Table=false;
	bool Error_Fill_Table_Frequency=false;
	bool Error_Fill_Table_Relative_Frequency=false;
	float ty[2][30]={{2.78,2.57,2.45,2.37,2.31,2.26,2.23,2.2,2.18,2.16,2.15,2.13,2.12,2.11,2.1,2.093,2.064,2.045,2.032,2.023,2.016,2.009,2.001,1.996,1.001,1.987,1.984,1.98,1.96},{5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35,40,45,50,60,70,80,90,100,120,0}};
	float qy[2][30]={{1.37,1.09,0.92,0.8,0.71,0.65,0.59,0.55,0.52,0.48,0.46,0.44,0.42,0.4,0.39,0.37,0.32,0.28,0.26,0.24,0.22,0.21,0.188,0.174,0.161,0.151,0.143,0.115,0.099,0.089},{5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35,40,45,50,60,70,80,90,100,150,200,250}};

	QGraphicsTextItem* text;
	QGraphicsScene *scene_1;
	QGraphicsScene *scene_2;
	QGraphicsScene *scene_3;
	QGraphicsScene *scene_4;
	QGraphicsScene *scene_5;
	QGraphicsScene *scene_6;

	//Цвета перьев
	QPen pen(Qt::black);
	QPen pen2(Qt::blue);
	QPen pen3(Qt::gray);
	QPen pen4(Qt::cyan);

	if(!ui.k_widget->value())
		QMessageBox::warning(0, "Ошибка ввода данных", "Поле \"Количество интервалов\" было заполнено неверно");
	else
	{
		if(Table_is_Full)
		{
//=======================================================================================================================//
//=============================== Проверка таблицы данных на правильность введенных данных ==============================//
//=======================================================================================================================//
			for(int i=0;i<ui.Table->rowCount();i++)
				for(int j=0;j<ui.Table->columnCount();j++)
				{
					if(ui.Table->item(i,j) == 0)
						Error_Fill_Table=true;//В таблице содежатся неверные данные
					else
					{
						(ui.Table->item(i,j))->text().toFloat(&ok);
						if(!ok)Error_Fill_Table=true;//В таблице содежатся неверные данные
					}
				}

			if(!Error_Fill_Table)
			{
//=======================================================================================================================//
//============================================= Определение первичных данных ============================================//
//=======================================================================================================================//
				float min=((ui.Table->item(0,0))->text()).toFloat();
				float max=((ui.Table->item(0,0))->text()).toFloat();			

				for(int i=0;i<ui.Table->rowCount();i++)
					for(int j=0;j<ui.Table->columnCount();j++)
					{
						min=(((ui.Table->item(i,j))->text()).toFloat()<min)?((ui.Table->item(i,j))->text()).toFloat():min;
						max=(((ui.Table->item(i,j))->text()).toFloat()>max)?((ui.Table->item(i,j))->text()).toFloat():max;
					}

				h=(max-min)/ui.k_widget->value();
				x0=min;//x0=min-(h/2);

				Create_Tables();
//=======================================================================================================================//
//============================================== Построение таблицы частот ==============================================//
//=======================================================================================================================//
				for(int x=0;x<ui.k_widget->value();x++)
				{
					//Выыод интервала
					if(x!=ui.k_widget->value()-1) tmp_str=("["+QString::number(x0+x*h,  'g',  4)+" ; "+QString::number(x0+(x+1)*h,  'g',  4)+")");//Возможно не 4?!
					else tmp_str=("["+QString::number(x0+x*h,  'g',  4)+" ; "+QString::number(x0+(x+1)*h,  'g',  4)+"]");//Возможно не 4?!

					item = new  QTableWidgetItem(tmp_str);
					item->setTextAlignment(Qt::AlignCenter);
					ui.Table_2->setItem(0,x+1, item);

					//Выыод частоты появления в интервале
					for(int i=0;i<ui.Table->rowCount();i++)
						for(int j=0;j<ui.Table->columnCount();j++)
						{
							if(x!=ui.k_widget->value()-1)
							{
								if( ((x0+x*h)<=ui.Table->item(i,j)->text().toFloat()) && (ui.Table->item(i,j)->text().toFloat()<(x0+(x+1)*h)) )
									count++;
							}
							else
							{
									if( ((x0+x*h)<=ui.Table->item(i,j)->text().toFloat()) && (ui.Table->item(i,j)->text().toFloat()<=(x0+(x+1)*h)) )
									count++;
							}
						}
				
					item = new  QTableWidgetItem(QString::number(count));
					item->setTextAlignment(Qt::AlignCenter);
					ui.Table_2->setItem(1,x+1, item);
					sum+=count;
					count=0;
				}
//=======================================================================================================================//
				ui.Sum->setText(QString::number(sum));//Вывод суммы частот
//=======================================================================================================================//
//============================================= Построение таблицы частостей ============================================//
//=======================================================================================================================//
				for(int x=0;x<ui.k_widget->value();x++)
				{
					if(x!=ui.k_widget->value()-1) tmp_str=("["+QString::number(x0+x*h,  'g',  4)+" ; "+QString::number(x0+(x+1)*h,  'g',  4)+")");//Возможно не 4?!
					else tmp_str=("["+QString::number(x0+x*h,  'g',  4)+" ; "+QString::number(x0+(x+1)*h,  'g',  4)+"]");//Возможно не 4?!

					item = new  QTableWidgetItem(tmp_str);
					item->setTextAlignment(Qt::AlignCenter);
					ui.Table_3->setItem(0,x+1, item);

					for(int i=0;i<ui.Table->rowCount();i++)
						for(int j=0;j<ui.Table->columnCount();j++)
						{
							if(x!=ui.k_widget->value()-1)
							{
								if( ((x0+x*h)<=ui.Table->item(i,j)->text().toFloat()) && (ui.Table->item(i,j)->text().toFloat()<(x0+(x+1)*h)) )
								count++;
							}
							else
							{
								if( ((x0+x*h)<=ui.Table->item(i,j)->text().toFloat()) && (ui.Table->item(i,j)->text().toFloat()<=(x0+(x+1)*h)) )
								count++;
							}
						}
					item = new  QTableWidgetItem(QString::number((float)count/(float)sum,  'g',  2));//Возможно не 2?!
					item->setTextAlignment(Qt::AlignCenter);
					ui.Table_3->setItem(1,x+1, item);
					count=0;
				}
			}
			else QMessageBox::warning(0, "Ошибка при считывании данных", "    Возможно в таблице содержатся неверные данные.\nПожалуйста, проверьте правильность введенных данных.");
//=======================================================================================================================//
		}
		else
		{
			Minus=false;
//=======================================================================================================================//
//=============================== Проверка таблицы частот на правильность введенных данных ==============================//
//=======================================================================================================================//
			count=0;
			for(int i=0;i<ui.Table_2->rowCount();i++)
				for(int j=1;j<ui.Table_2->columnCount();j++)
				{
					if(ui.Table_2->item(i,j) == 0)
						Error_Fill_Table_Frequency=true;//В таблице содежатся неверные данные
					else count++;
				}

			if(count==2*(ui.Table_2->columnCount()-1))	Table_Frequency_is_Full=true;
			else Table_Frequency_is_Full=false;
//=======================================================================================================================//
//=============================== Проверка таблицы частот на правильность введенных данных ==============================//
//=======================================================================================================================//
			count=0;
			for(int i=0;i<ui.Table_3->rowCount();i++)
				for(int j=1;j<ui.Table_3->columnCount();j++)
				{
					if(ui.Table_3->item(i,j) == 0)
						Error_Fill_Table_Relative_Frequency=true;//В таблице содежатся неверные данные
					else count++;
				}

			if(count==2*(ui.Table_3->columnCount()-1))	Table_Relative_Frequency_is_Full=true;
			else Table_Relative_Frequency_is_Full=false;
//=======================================================================================================================//
			if(ui.Sum->text()=="")QMessageBox::warning(0, "Ошибка ввода данных", "Поле \"Сумма частот (N)\" было заполнено неверно");
			else
			{
//=======================================================================================================================//
//============================================= Определение первичных данных ============================================//
//=======================================================================================================================//
				if(Table_Frequency_is_Full || Table_Relative_Frequency_is_Full)
				{
					int i=0;

					if(Table_Frequency_is_Full && Table_Relative_Frequency_is_Full)
					{
						if(ui.tabWidget_2->currentIndex()==0)
						{
							string_item = ui.Table_2->item(0,1)->text();//Строка в ячейке
							for(int x=1;x<=ui.k_widget->value();x++)
							{
								item = new  QTableWidgetItem(ui.Table_2->item(0,x)->text());
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_3->setItem(0,x, item);

								item = new  QTableWidgetItem(QString::number((ui.Table_2->item(1,x)->text().toFloat()/ui.Sum->text().toFloat()), 'g', 2));
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_3->setItem(1,x, item);
							}
						}
						if(ui.tabWidget_2->currentIndex()==1)
						{
							string_item = ui.Table_3->item(0,1)->text();//Строка в ячейке

							for(int x=1;x<=ui.k_widget->value();x++)
							{
								item = new  QTableWidgetItem(ui.Table_3->item(0,x)->text());
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_2->setItem(0,x, item);

								item = new  QTableWidgetItem(QString::number((ui.Table_3->item(1,x)->text().toFloat()*ui.Sum->text().toFloat()), 'g', 2));
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_2->setItem(1,x, item);
							}
						}
					}
					else
					{
						if(Table_Frequency_is_Full)
						{
							string_item = ui.Table_2->item(0,1)->text();//Строка в ячейке
							for(int x=1;x<=ui.k_widget->value();x++)
							{
								item = new  QTableWidgetItem(ui.Table_2->item(0,x)->text());
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_3->setItem(0,x, item);

								item = new  QTableWidgetItem(QString::number((ui.Table_2->item(1,x)->text().toFloat()/ui.Sum->text().toFloat()), 'g', 2));
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_3->setItem(1,x, item);
							}
						}
						if(Table_Relative_Frequency_is_Full)
						{
							string_item = ui.Table_3->item(0,1)->text();//Строка в ячейке

							for(int x=1;x<=ui.k_widget->value();x++)
							{
								item = new  QTableWidgetItem(ui.Table_3->item(0,x)->text());
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_2->setItem(0,x, item);

								item = new  QTableWidgetItem(QString::number((ui.Table_3->item(1,x)->text().toFloat()*ui.Sum->text().toFloat()), 'g', 2));
								item->setTextAlignment(Qt::AlignCenter);
								ui.Table_2->setItem(1,x, item);
							}
						}
					}

					for(i=0;i<string_item.size() && string_item[i]!=';';i++)
					{
						if(string_item[i]=='-')Minus=true;
						if(string_item[i]!='['&&string_item[i]!=' ')tmp_str_1+=string_item[i];
					}
					for(int j=i+1;j<string_item.size() && string_item[j]!=')' && string_item[j]!=']';j++)
					{
						if(string_item[j]=='-')Minus=true;
						if(string_item[j]!=' ')tmp_str_2+=string_item[j];
					}

					h=(tmp_str_2.toFloat()-tmp_str_1.toFloat());

					x0=tmp_str_1.toFloat();
				}
				else QMessageBox::warning(0, "Ошибка при считывании данных из файла", "Возможно в файле содержатся неверные данные.\n  Пожалуйста, попробуйте выбрать другой файл\n           или исправьте ошибки в текущем.");
			}
		}
//=======================================================================================================================//
//======================================== Определение средних величин ==================================================//
//=======================================================================================================================//
		float SS=0;
		for(int x=1;x<=ui.k_widget->value();x++)
		{
			SS+=(((x0+(x-1)*h)+(x0+(x)*h))/2)*ui.Table_2->item(1,x)->text().toFloat();
		}
		ui.X->setText(QString::number((SS/ui.Sum->text().toFloat()), 'g', 4));
//=======================================================================================================================//
		SS=0;
		for(int x=1;x<=ui.k_widget->value();x++)
		{
			SS+=pow(((((x0+(x-1)*h)+(x0+(x)*h))/2)-ui.X->text().toFloat()),2)*ui.Table_2->item(1,x)->text().toFloat();
		}
		ui.D->setText(QString::number((ui.Sum->text().toFloat()<30)?(1/(ui.Sum->text().toFloat()-1)*SS):(SS/ui.Sum->text().toFloat()), 'g', 4));
//=======================================================================================================================//
		ui.S->setText(QString::number(sqrt(ui.D->text().toFloat()),'g', 4));
//=======================================================================================================================//
		int i=0;
		for(i=0;i<30;i++)
			if(ui.Sum->text().toFloat()<ty[1][i])break;
		i--;

		float Eps=(ui.S->text().toFloat()*ty[0][i])/sqrt(ui.Sum->text().toFloat());//ty[1][4];
		ui.A->setText("["+QString::number(ui.X->text().toFloat()-Eps,'g', 4)+" ; "+QString::number(ui.X->text().toFloat()+Eps,'g', 4)+"]");
//=======================================================================================================================//
		for(i=0;i<30;i++)
			if(ui.Sum->text().toFloat()<qy[1][i])break;
		i--;
		ui.Sigma->setText("["+QString::number(ui.S->text().toFloat()*(1-qy[0][i]),'g', 4)+" ; "+QString::number(ui.S->text().toFloat()*(1+qy[0][i]),'g', 4)+"]");
//=======================================================================================================================//
//=========================== Определение коэффициентов сопоставления (для отрисовки графиков) ==========================//
//=======================================================================================================================//
		//Определение границ для сопоставления по оси Х
		float start_graphics=x0-h/2;
		float finish_graphics=(x0+(ui.k_widget->value()*h)+h/2);

		//Коэффициент сопоставления по оси Х
		coefficient_x=270/(finish_graphics-start_graphics);

		//Поиск максимальной высоты у прямоугольников графика гистограммы
		float y_max=ui.Table_2->item(1,1)->text().toFloat()/(ui.Sum->text().toFloat()*h);

		for(int x=2;x<=ui.k_widget->value();x++)
			if(y_max<ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h))y_max=ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h);

		//Коэффициент сопоставления по оси Y
		coefficient_y=230/y_max;
		yy_max=y_max;

		//Ориентация графиков
		if(!Minus)
		{
			start_point=-60;
			finish_point=200;
		}
		else 
		{
			start_point=200;
			finish_point=-60;
		}
//=======================================================================================================================//
//========================================== Отрисовка графика гистограммы частот =======================================//
//=======================================================================================================================//
		scene_1 = new QGraphicsScene(ui.Browser); 

		//Отрисовка системы координат
		scene_1->addLine(-60,230,200,230,pen);//Ось X
		scene_1->addLine(start_point,0,start_point,230,pen);//Ось y
		scene_1->addLine(start_point,0,start_point+5,5,pen);//Стрелка - ось y
		scene_1->addLine(start_point,0,start_point-5,5,pen);//Стрелка - ось y
		if(!Minus)
		{
			scene_1->addLine(finish_point-5,225,finish_point,230,pen);//Стрелка - ось X
			scene_1->addLine(finish_point-5,235,finish_point,230,pen);//Стрелка - ось X
		}
		
		text = scene_1->addText("0", QFont("Arial", 6 ));
		text->setPos((!Minus)?-74:214,230);

		text = scene_1->addText("...", QFont("Arial", 10 ));
		text->setPos((!Minus)?-64:200,225);

		for(int x=1;x<=ui.k_widget->value();x++)
		{
			for(int i=-60-h/2*coefficient_x+h*coefficient_x*x+1;i<-60+h/2*coefficient_x+h*coefficient_x*x;i++)
				scene_1->addLine(i,229,i,229-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,pen4);//Закраска "прямоугольника"

			scene_1->addLine(-60-h/2*coefficient_x+h*coefficient_x*x,229,-60-h/2*coefficient_x+h*coefficient_x*x,229-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,pen2);//Левая грань "прямоугольника"
			scene_1->addLine(-60+h/2*coefficient_x+h*coefficient_x*x,229,-60+h/2*coefficient_x+h*coefficient_x*x,229-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,pen2);//Правая грань "прямоугольника"
			scene_1->addLine(-60-h/2*coefficient_x+h*coefficient_x*x,229-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,-60+h/2*coefficient_x+h*coefficient_x*x,229-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,pen2);//Макушка "прямоугольника"
			
			//Отображение значений кооржинат вдоль оси X
			text = scene_1->addText(QString::number((x0+((x-1)*h)),  'g',  4), QFont("Arial", 6 ));
			text->setPos(-66-h/2*coefficient_x+h*coefficient_x*x,230);

			//Отображение значений кооржинат вдоль оси Y
			text = scene_1->addText(QString::number(ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h),  'g',  2), QFont("Arial", 6 ));
			text->setPos((!Minus)?-84:200,224-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y);
		}

		//Отображение значений кооржинат вдоль оси X - последнее значение
		text = scene_1->addText(QString::number((x0+((ui.k_widget->value())*h)),  'g',  4), QFont("Arial", 6 ));
		text->setPos(-66-h/2*coefficient_x+h*coefficient_x*(ui.k_widget->value()+1),230);

		ui.Browser->setScene(scene_1);
//=======================================================================================================================//
//============================================= Отрисовка графика полигона частот =======================================//
//=======================================================================================================================//
		scene_2 = new QGraphicsScene(ui.Browser_2); 

		//Отрисовка системы координат
		scene_2->addLine(-60,230,200,230,pen);//Ось X
		scene_2->addLine(start_point,0,start_point,230,pen);//Ось y
		scene_2->addLine(start_point,0,start_point+5,5,pen);//Стрелка - ось y
		scene_2->addLine(start_point,0,start_point-5,5,pen);//Стрелка - ось y
		if(!Minus)
		{
			scene_2->addLine(finish_point-5,225,finish_point,230,pen);//Стрелка - ось X
			scene_2->addLine(finish_point-5,235,finish_point,230,pen);//Стрелка - ось X
		}

		text = scene_2->addText("0", QFont("Arial", 6 ));
		text->setPos((!Minus)?-74:214,230);//

		text = scene_2->addText("...", QFont("Arial", 10 ));
		text->setPos((!Minus)?-64:200,225);//

		for(int x=1;x<=ui.k_widget->value();x++)
		{
			scene_2->addLine(-60+h*coefficient_x*x,230,-60+h*coefficient_x*x,230-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,pen3);//Левая грань "прямоугольника"
			if(x!=ui.k_widget->value())scene_2->addLine(-60+h*coefficient_x*x,230-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,-60+h*coefficient_x*(x+1),230-ui.Table_2->item(1,x+1)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y,pen2);//Макушка "прямоугольника"

			//Отображение значений кооржинат вдоль оси X
			text = scene_2->addText(QString::number((h/2+x0+((x-1)*h)),  'g',  4), QFont("Arial", 6 ));
			text->setPos(-66+h*coefficient_x*x,230);//

			//Отображение значений кооржинат вдоль оси Y
			text = scene_2->addText(QString::number(ui.Table_2->item(1,x)->text().toFloat()/ui.Sum->text().toFloat(),  'g',  2), QFont("Arial", 6 ));
			text->setPos((!Minus)?-84:200,224-ui.Table_2->item(1,x)->text().toFloat()/(ui.Sum->text().toFloat()*h)*coefficient_y);
		}

		ui.Browser_2->setScene(scene_2);
//=======================================================================================================================//
//===================================== Отрисовка эмпирической функции распределения ====================================//
//=======================================================================================================================//			
		scene_3 = new QGraphicsScene(ui.Browser_3); 

		QByteArray Function="";//QString Function="";
		SS=0;

		Function+="             /   0 при x < "+QString::number((x0+h)/*(x0)*/, 'g', 4)+"\n";

		for(int x=1;x<ui.k_widget->value();x++)
		{
			SS+=ui.Table_3->item(1,x)->text().toFloat();

			if((x+1)!=(ui.k_widget->value()+2)/2) Function+="             |   "+QString::number(SS, 'g', 4)+" при "+QString::number((x0+((x)/*(x-1)*/*h)), 'g', 4)+" <= x < "+QString::number(((x0+((x+1)/*(x)*/*h))), 'g', 4)+"\n";
			else Function+="F(x)= <    "+QString::number(SS, 'g', 4)+" при "+QString::number((x0+(((x))/*(x-1)*/*h)), 'g', 4)+" <= x < "+QString::number(((x0+((x+1)/*(x)*/*h))), 'g', 4)+"\n";
		}
		Function+="             \\   "+QString::number(1, 'g', 4)+" при x >= "+QString::number(((x0+((ui.k_widget->value()/*-1*/)*h))), 'g', 4)+"\n";

		scene_3->addText(Function);

		ui.Browser_3->setScene(scene_3);
//=======================================================================================================================//
//================================== Отрисовка графика эмпирической функции распределения ===============================//
//=======================================================================================================================//
		//Коэффициент сопоставления по оси Y
		coefficient_y=230/1;

		scene_4 = new QGraphicsScene(ui.Browser_4);

		//Отрисовка системы координат
		scene_4->addLine(-60,230,200,230,pen);//Ось X
		scene_4->addLine(start_point,0,start_point,230,pen);//Ось y
		scene_4->addLine(start_point,0,start_point+5,5,pen);//Стрелка - ось y
		scene_4->addLine(start_point,0,start_point-5,5,pen);//Стрелка - ось y
		if(!Minus)
		{
			scene_4->addLine(finish_point-5,225,finish_point,230,pen);//Стрелка - ось X
			scene_4->addLine(finish_point-5,235,finish_point,230,pen);//Стрелка - ось X
		}

		text = scene_4->addText("0", QFont("Arial", 6 ));
		text->setPos((!Minus)?-74:214,230);

		text = scene_4->addText("...", QFont("Arial", 10 ));
		text->setPos((!Minus)?-64:200,225);

		SS=0;

		scene_4->addLine(-60,230-SS*coefficient_y,-60+h/2*coefficient_x,+230-SS*coefficient_y,pen2);//Горизонтальная прямая
		/*scene_4->addLine(-60,230-SS*coefficient_y,-55,+230-SS*coefficient_y-5,pen2);//Стрелка на горизонтальной прямой
		scene_4->addLine(-60,230-SS*coefficient_y,-55,+230-SS*coefficient_y+5,pen2);//Стрелка на горизонтальной прямой*/

		for(int x=1;x<=ui.k_widget->value();x++)
		{
			//Отображение значений координат вдоль оси X
			text = scene_4->addText(QString::number((x0+(x)*h/*(x-1)*/), 'g', 4), QFont("Arial", 6 ));
			text->setPos(-66-h/2*coefficient_x+h*coefficient_x*(x),230);

			SS+=ui.Table_3->item(1,x)->text().toFloat();

			//Отображение значений кооржинат вдоль оси Y
			text = scene_4->addText(QString::number(SS,  'g',  2), QFont("Arial", 6 ));
			text->setPos((!Minus)?-84:200,224-SS*coefficient_y);

			scene_4->addLine(-60-h/2*coefficient_x+h*coefficient_x*(x),230-SS*coefficient_y,-60+h/2*coefficient_x+h*coefficient_x*(x),230-SS*coefficient_y,pen2);//Горизонтальная прямая
			scene_4->addLine(-60+h/2*coefficient_x+h*coefficient_x*(x-1),230,-60+h/2*coefficient_x+h*coefficient_x*(x-1),230-SS*coefficient_y,pen3);//Вертикальная прямая

			scene_4->addLine(-60-h/2*coefficient_x+h*coefficient_x*(x),230-SS*coefficient_y,-60-h/2*coefficient_x+h*coefficient_x*(x)+5,230-SS*coefficient_y+5,pen2);//Стрелка на горизонтальной прямой
			scene_4->addLine(-60-h/2*coefficient_x+h*coefficient_x*(x),230-SS*coefficient_y,-60-h/2*coefficient_x+h*coefficient_x*(x)+5,230-SS*coefficient_y-5,pen2);//Стрелка на горизонтальной прямой
		}
		ui.Browser_4->setScene(scene_4);
//=======================================================================================================================//
	}
}

void TerVer_Lab1:: Zoom_Graphic_Histogram()
{
	int mas_size=100;
	float* mas;
	mas = (float*)malloc(sizeof(float)*mas_size);

//// Создания массива частот появления элементов для передачи в другое окно 
// Аналогично for(int x=1;x<=ui.k_widget->value();x++)ui.Table_2->item(1,x)->text().toInt();
	for(int x=1;x<=ui.k_widget->value();x++)
	{
		if(x == mas_size)
		{
			mas_size*=2;
			mas = (float*)realloc(mas, sizeof(float)*mas_size);
		}
		int bnv=ui.Table_2->item(1,x)->text().toInt();
		mas[x-1]=ui.Table_2->item(1,x)->text().toInt();
	}

	Scaling_Graphics *mm = new Scaling_Graphics(1,mas,ui.k_widget->value(),Minus,coefficient_x*2,(230/yy_max)*2,h,x0,ui.Sum->text().toFloat(),0);
	mm->show();
}

void TerVer_Lab1::Zoom_Graphic_Relative_Frequencies()
{
	int mas_size=100;
	float* mas;
	mas = (float*)malloc(sizeof(float)*mas_size);

//// Создания массива частот появления элементов для передачи в другое окно 
// Аналогично for(int x=1;x<=ui.k_widget->value();x++)ui.Table_2->item(1,x)->text().toInt();
	for(int x=1;x<=ui.k_widget->value();x++)
	{
		if(x == mas_size)
		{
			mas_size*=2;
			mas = (float*)realloc(mas, sizeof(float)*mas_size);
		}
		int bnv=ui.Table_2->item(1,x)->text().toInt();
		mas[x-1]=ui.Table_2->item(1,x)->text().toInt();
	}

	Scaling_Graphics *mm = new Scaling_Graphics(2,mas,ui.k_widget->value(),Minus,coefficient_x*2,(230/yy_max)*2,h,x0,ui.Sum->text().toFloat(),0);
	mm->show();
}

void TerVer_Lab1::Zoom_Graphic_Empirical_Function()
{
	int mas_size=100;
	float* mas;
	mas = (float*)malloc(sizeof(float)*mas_size);

//// Создания массива вероятностей появления элементов для передачи в другое окно 
// Аналогично for(int x=1;x<=ui.k_widget->value();x++)ui.Table_3->item(1,x)->text().toInt();
	for(int x=1;x<=ui.k_widget->value();x++)
	{
		if(x == mas_size)
		{
			mas_size*=2;
			mas = (float*)realloc(mas, sizeof(float)*mas_size);
		}
		float bnv=ui.Table_3->item(1,x)->text().toFloat();
		mas[x-1]=ui.Table_3->item(1,x)->text().toFloat();
	}

	Scaling_Graphics *mm = new Scaling_Graphics(3,mas,ui.k_widget->value(),Minus,coefficient_x*2,(230/1)*2,h,x0,ui.Sum->text().toFloat(),0);
	mm->show();
}
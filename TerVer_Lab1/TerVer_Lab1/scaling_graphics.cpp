#include "scaling_graphics.h"

Scaling_Graphics::Scaling_Graphics(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Scaling_Graphics::Scaling_Graphics(int type,float *mas,int k,bool Minus,float coefficient_x,float coefficient_y,float h,float x0,float Sum,QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	QGraphicsScene *scene = new QGraphicsScene(ui.graphicsView);
	QGraphicsTextItem* text;

	int start_point=-120;
	int finish_point=400;

	//Цвета перьев
	QPen pen(Qt::black);
	QPen pen2(Qt::blue);
	QPen pen3(Qt::gray);
	QPen pen4(Qt::cyan);
	
	//Ориентация графиков
	if(!Minus)
	{
		start_point=-120;
		finish_point=400;
	}
	else 
	{
		start_point=400;
		finish_point=-120;
	}
	coefficient_x;
	coefficient_y;

	//Отрисовка системы координат
	scene->addLine(-120,460,400,460,pen);//Ось X
	scene->addLine(start_point,0,start_point,460,pen);//Ось y
	scene->addLine(start_point,0,start_point+5,5,pen);//Стрелка - ось y
	scene->addLine(start_point,0,start_point-5,5,pen);//Стрелка - ось y
	
	if(!Minus)
	{
		scene->addLine(finish_point-5,465,finish_point,460,pen);//Стрелка - ось X
		scene->addLine(finish_point-5,455,finish_point,460,pen);//Стрелка - ось X
	}

	text = scene->addText("0", QFont("Arial", 6 ));
	text->setPos((!Minus)?-148:428,460);

	text = scene->addText("...", QFont("Arial", 10 ));
	text->setPos((!Minus)?-138:400,450);

	if(type == 1)
	{
		for(int x=0;x<k;x++)
		{
			for(int i=-120-h/2*coefficient_x+h*coefficient_x*(x+1);i<-120+h/2*coefficient_x+h*coefficient_x*(x+1);i++)
				scene->addLine(i,459,i,459-mas[x]/(Sum*h)*coefficient_y,pen4);//Закраска "прямоугольника"

			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),459,-120-h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen2);//Левая грань "прямоугольника"
			scene->addLine(-120+h/2*coefficient_x+h*coefficient_x*(x+1),459,-120+h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen2);//Правая грань "прямоугольника"
			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,-120+h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen2);//Макушка "прямоугольника"
			//scene->addLine(-120,459-mas[x]/(Sum*h)*coefficient_y,-120+h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen4);//Макушка "прямоугольника"

			//Отображение значений кооржинат вдоль оси X
			text = scene->addText(QString::number((x0+((x/*-1*/)*h)),  'g',  4), QFont("Arial", 6 ));
			text->setPos(-132-h/2*coefficient_x+h*coefficient_x*(x+1),460);

			//Отображение значений кооржинат вдоль оси Y
			text = scene->addText(QString::number(mas[x]/(Sum*h),  'g',  3), QFont("Arial", 6 ));
			text->setPos((!Minus)?-150:400,450-mas[x]/(Sum*h)*coefficient_y);
		}

		//Отображение значений кооржинат вдоль оси X - последнее значение
		text = scene->addText(QString::number((x0+k*h),  'g',  4), QFont("Arial", 6 ));
		text->setPos(-132-h/2*coefficient_x+h*coefficient_x*(k+1),460);
	}
	if(type==2)
	{
		for(int x=0;x<k;x++)
		{
			scene->addLine(-120+h*coefficient_x*(x+1),460,-120+h*coefficient_x*(x+1),460-mas[x]/(Sum*h)*coefficient_y,pen3);//Левая грань "прямоугольника"
			if(x!=k-1)scene->addLine(-120+h*coefficient_x*(x+1),460-mas[x]/(Sum*h)*coefficient_y,-120+h*coefficient_x*(x+2),460-mas[x+1]/(Sum*h)*coefficient_y,pen2);//Макушка "прямоугольника"

			//Отображение значений кооржинат вдоль оси X
			text = scene->addText(QString::number((h/2+x0+((x)*h)),  'g',  4), QFont("Arial", 6 ));
			text->setPos(-132+h*coefficient_x*(x+1),460);//

			//Отображение значений кооржинат вдоль оси Y
			text = scene->addText(QString::number(mas[x]/Sum,  'g',  3), QFont("Arial", 6 ));
			text->setPos((!Minus)?-150:400,454-mas[x]/(Sum*h)*coefficient_y);
		}
	}
	if(type==3)
	{
		float SS=0;
		scene->addLine(-120,460-SS*coefficient_y,-120+h/2*coefficient_x,+460-SS*coefficient_y,pen2);//Горизонтальная прямая

		for(int x=0;x<k;x++)
		{
			//Отображение значений координат вдоль оси X
			text = scene->addText(QString::number((x0+(x+1)*h), 'g', 4), QFont("Arial", 6 ));
			text->setPos(-132-h/2*coefficient_x+h*coefficient_x*(x+1),460);

			SS+=mas[x];

			//Отображение значений кооржинат вдоль оси Y
			text = scene->addText(QString::number(SS,  'g',  3), QFont("Arial", 6 ));
			text->setPos((!Minus)?-150:400,450-SS*coefficient_y);

			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,-120+h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,pen2);//Горизонтальная прямая
			scene->addLine(-120+h/2*coefficient_x+h*coefficient_x*(x),460,-120+h/2*coefficient_x+h*coefficient_x*(x),460-SS*coefficient_y,pen3);//Вертикальная прямая

			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,-120-h/2*coefficient_x+h*coefficient_x*(x+1)+5,460-SS*coefficient_y+5,pen2);//Стрелка на горизонтальной прямой
			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,-120-h/2*coefficient_x+h*coefficient_x*(x+1)+5,460-SS*coefficient_y-5,pen2);//Стрелка на горизонтальной прямой
		}
	}
	ui.graphicsView->setScene(scene);
}

Scaling_Graphics::~Scaling_Graphics()
{

}

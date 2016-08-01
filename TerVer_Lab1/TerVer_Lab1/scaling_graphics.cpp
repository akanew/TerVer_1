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

	//����� ������
	QPen pen(Qt::black);
	QPen pen2(Qt::blue);
	QPen pen3(Qt::gray);
	QPen pen4(Qt::cyan);
	
	//���������� ��������
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

	//��������� ������� ���������
	scene->addLine(-120,460,400,460,pen);//��� X
	scene->addLine(start_point,0,start_point,460,pen);//��� y
	scene->addLine(start_point,0,start_point+5,5,pen);//������� - ��� y
	scene->addLine(start_point,0,start_point-5,5,pen);//������� - ��� y
	
	if(!Minus)
	{
		scene->addLine(finish_point-5,465,finish_point,460,pen);//������� - ��� X
		scene->addLine(finish_point-5,455,finish_point,460,pen);//������� - ��� X
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
				scene->addLine(i,459,i,459-mas[x]/(Sum*h)*coefficient_y,pen4);//�������� "��������������"

			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),459,-120-h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen2);//����� ����� "��������������"
			scene->addLine(-120+h/2*coefficient_x+h*coefficient_x*(x+1),459,-120+h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen2);//������ ����� "��������������"
			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,-120+h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen2);//������� "��������������"
			//scene->addLine(-120,459-mas[x]/(Sum*h)*coefficient_y,-120+h/2*coefficient_x+h*coefficient_x*(x+1),459-mas[x]/(Sum*h)*coefficient_y,pen4);//������� "��������������"

			//����������� �������� ��������� ����� ��� X
			text = scene->addText(QString::number((x0+((x/*-1*/)*h)),  'g',  4), QFont("Arial", 6 ));
			text->setPos(-132-h/2*coefficient_x+h*coefficient_x*(x+1),460);

			//����������� �������� ��������� ����� ��� Y
			text = scene->addText(QString::number(mas[x]/(Sum*h),  'g',  3), QFont("Arial", 6 ));
			text->setPos((!Minus)?-150:400,450-mas[x]/(Sum*h)*coefficient_y);
		}

		//����������� �������� ��������� ����� ��� X - ��������� ��������
		text = scene->addText(QString::number((x0+k*h),  'g',  4), QFont("Arial", 6 ));
		text->setPos(-132-h/2*coefficient_x+h*coefficient_x*(k+1),460);
	}
	if(type==2)
	{
		for(int x=0;x<k;x++)
		{
			scene->addLine(-120+h*coefficient_x*(x+1),460,-120+h*coefficient_x*(x+1),460-mas[x]/(Sum*h)*coefficient_y,pen3);//����� ����� "��������������"
			if(x!=k-1)scene->addLine(-120+h*coefficient_x*(x+1),460-mas[x]/(Sum*h)*coefficient_y,-120+h*coefficient_x*(x+2),460-mas[x+1]/(Sum*h)*coefficient_y,pen2);//������� "��������������"

			//����������� �������� ��������� ����� ��� X
			text = scene->addText(QString::number((h/2+x0+((x)*h)),  'g',  4), QFont("Arial", 6 ));
			text->setPos(-132+h*coefficient_x*(x+1),460);//

			//����������� �������� ��������� ����� ��� Y
			text = scene->addText(QString::number(mas[x]/Sum,  'g',  3), QFont("Arial", 6 ));
			text->setPos((!Minus)?-150:400,454-mas[x]/(Sum*h)*coefficient_y);
		}
	}
	if(type==3)
	{
		float SS=0;
		scene->addLine(-120,460-SS*coefficient_y,-120+h/2*coefficient_x,+460-SS*coefficient_y,pen2);//�������������� ������

		for(int x=0;x<k;x++)
		{
			//����������� �������� ��������� ����� ��� X
			text = scene->addText(QString::number((x0+(x+1)*h), 'g', 4), QFont("Arial", 6 ));
			text->setPos(-132-h/2*coefficient_x+h*coefficient_x*(x+1),460);

			SS+=mas[x];

			//����������� �������� ��������� ����� ��� Y
			text = scene->addText(QString::number(SS,  'g',  3), QFont("Arial", 6 ));
			text->setPos((!Minus)?-150:400,450-SS*coefficient_y);

			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,-120+h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,pen2);//�������������� ������
			scene->addLine(-120+h/2*coefficient_x+h*coefficient_x*(x),460,-120+h/2*coefficient_x+h*coefficient_x*(x),460-SS*coefficient_y,pen3);//������������ ������

			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,-120-h/2*coefficient_x+h*coefficient_x*(x+1)+5,460-SS*coefficient_y+5,pen2);//������� �� �������������� ������
			scene->addLine(-120-h/2*coefficient_x+h*coefficient_x*(x+1),460-SS*coefficient_y,-120-h/2*coefficient_x+h*coefficient_x*(x+1)+5,460-SS*coefficient_y-5,pen2);//������� �� �������������� ������
		}
	}
	ui.graphicsView->setScene(scene);
}

Scaling_Graphics::~Scaling_Graphics()
{

}

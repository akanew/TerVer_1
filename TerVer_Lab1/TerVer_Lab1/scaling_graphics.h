#ifndef SCALING_GRAPHICS_H
#define SCALING_GRAPHICS_H

#include <QWidget>
#include "ui_scaling_graphics.h"
#include <QGraphicsItem>

class Scaling_Graphics : public QWidget
{
	Q_OBJECT

public:
	Scaling_Graphics(QWidget *parent = 0);
	Scaling_Graphics(int type,float *mas,int k,bool Minus,float coefficient_x,float coefficient_y,float h,float x0,float Sum,QWidget *parent = 0);//scene_2 = new QGraphicsScene(ui.Browser_2); 
	~Scaling_Graphics();

private:
	Ui::Scaling_Graphics ui;
};

#endif // SCALING_GRAPHICS_H

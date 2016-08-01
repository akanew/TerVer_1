#ifndef TERVER_LAB1_H
#define TERVER_LAB1_H

#include <QtGui/QMainWindow>
#include "ui_terver_lab1.h"
#include <QTextCodec>
#include "QFileDialog.h"
#include "QMessageBox.h"
#include "QTextStream.h"
#include <QGraphicsItem>
#include <math.h> 
#include <QPalette>
#include "scaling_graphics.h"

class TerVer_Lab1 : public QMainWindow
{
	Q_OBJECT

public:
	TerVer_Lab1(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TerVer_Lab1();

	bool Minus;
	bool Fractional_Number;
	bool Table_is_Full;
	bool Table_Frequency_is_Full;
	bool Table_Relative_Frequency_is_Full;
	float h;
	float x0;
	float coefficient_x;
	float coefficient_y;
	float yy_max;

private:
	Ui::TerVer_Lab1Class ui;

	private slots:
		void Open_Action();
		void Create_Table();
		void Create_Tables();
		void Calculate_Action();
		void Zoom_Graphic_Histogram();
		void Zoom_Graphic_Relative_Frequencies();
		void Zoom_Graphic_Empirical_Function();
};

#endif // TERVER_LAB1_H

#ifndef SWITCHITEMVIEW_H
#define SWITCHITEMVIEW_H

#include <QWidget>
#include <QString>

#include "ui_switchitemview.h"

class SwitchItemView : public QWidget, private Ui::SwitchItemViewWidget
{
	Q_OBJECT
public:
	SwitchItemView(QWidget *parent = 0);
	SwitchItemView(const QString &text, QWidget *parent = 0);
	~SwitchItemView();
public:
	//-------- getter/setter --------S
	void setText(const QString &text);
	QString text();
	//-------- getter/setter --------E
	void addItem(QWidget *item);
	void addStretch();
private slots:
////	void on_checkBox_stateChanged(int state);
private:
	void setupUi();
	void setupUi(const QString &text);
};
#endif // SWITCHITEMVIEW_H

#include "switchitemview.h"

#include <QDebug>

//-------- constructor/destructor --------S
SwitchItemView::SwitchItemView(QWidget *parent) : QWidget(parent)/*{{{*/
{
	qDebug("%s, %d: SwitchItemView::SwitchItemView(parent=[%p])", __FILE__, __LINE__, parent);
	setupUi();
}/*}}}*/

SwitchItemView::SwitchItemView(const QString &text, QWidget *parent) : QWidget(parent)/*{{{*/
{
	qDebug("%s, %d: SwitchItemView::SwitchItemView(text=[%s], parent=[%p])", __FILE__, __LINE__, qPrintable(text), parent);
	setupUi(text);
}/*}}}*/

SwitchItemView::~SwitchItemView()/*{{{*/
{
	qDebug("%s, %d: SwitchItemView::~SwitchItemView()", __FILE__, __LINE__);
}/*}}}*/
//-------- constructor/destructor --------E

//-------- public --------S
//-------- getter/setter --------S
void SwitchItemView::setText(const QString &text)/*{{{*/
{
	checkBox->setText(text);
}/*}}}*/
QString SwitchItemView::text()/*{{{*/
{
	return checkBox->text();
}/*}}}*/
//-------- getter/setter --------E
void SwitchItemView::addItem(QWidget *item)/*{{{*/
{
	itemLayout->addWidget(item);
}/*}}}*/
void SwitchItemView::addStretch()/*{{{*/
{
	itemLayout->addStretch();
}/*}}}*/
//-------- public --------E

//-------- slots --------S
////void SwitchItemView::on_checkBox_stateChanged(int state)/*{{{*/
////{
////	qDebug("%s, %d: on_checkBox_stateChanged(int state=[%d])", __FILE__, __LINE__, state);
////	if(state == Qt::Checked)
////	{
////		qDebug("%s, %d: show itemWidget", __FILE__, __LINE__);
////		itemWidget->show();
////	}
////	else
////	{
////		qDebug("%s, %d: hide itemWidget", __FILE__, __LINE__);
////		itemWidget->hide();
////	}
////}/*}}}*/
//-------- slots --------E

//-------- private --------S
void SwitchItemView::setupUi()/*{{{*/
{
	Ui::SwitchItemViewWidget::setupUi(this);
	itemWidget->hide();
	QObject::connect(checkBox, SIGNAL(toggled(bool))
			,itemWidget, SLOT(setVisible(bool)));
}/*}}}*/
void SwitchItemView::setupUi(const QString &text)/*{{{*/
{
	setupUi();
	checkBox->setText(text);
}/*}}}*/
//-------- private --------E

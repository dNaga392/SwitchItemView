#include <QApplication>
#include <QMainWindow>
#include <QLabel>

#include "switchitemview.h"

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);

	QMainWindow *mainWindow = new QMainWindow();
	QWidget *mainWidget = new QWidget(mainWindow);
	QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
	SwitchItemView *siw = NULL;
	QLabel *label = NULL;

	label = new QLabel(QString("IJN CV"));
	Q_CHECK_PTR(label);
	mainLayout->addWidget(label);

	// ��q�� setText�ŃO���[�v����ݒ肷��ꍇ
	siw = new SwitchItemView();
	Q_CHECK_PTR(siw);
	siw->setText(QString("1st Carrier Division"));
	label = new QLabel(QString("Akagi"));
	Q_CHECK_PTR(label);
	siw->addItem(label);
	label = new QLabel(QString("Kaga"));
	Q_CHECK_PTR(label);
	siw->addItem(label);
	siw->addStretch();
	mainLayout->addWidget(siw);

	// ��q�� �R���X�g���N�^�ŃO���[�v����ݒ肷��ꍇ
	siw = new SwitchItemView(QString("2nd Carrier Division"));
	label = new QLabel(QString("Soryu"));
	Q_CHECK_PTR(label);
	siw->addItem(label);
	label = new QLabel(QString("Hiryu"));
	Q_CHECK_PTR(label);
	siw->addItem(label);
	siw->addStretch();
	mainLayout->addWidget(siw);

	// �܍q�� �������e�����ŃO���[�v����ݒ肷��ꍇ
	siw = new SwitchItemView("5th Carrier Division");
	label = new QLabel("Shokaku");
	Q_CHECK_PTR(label);
	siw->addItem(label);
	label = new QLabel("Zuikaku");
	Q_CHECK_PTR(label);
	siw->addItem(label);
	siw->addStretch();
	mainLayout->addWidget(siw);

	mainLayout->addStretch();

	mainWindow->setCentralWidget(mainWidget);
	mainWindow->setWindowTitle("SwitchItemViewTestApp");

	mainWindow->show();
	
	return app.exec();
}


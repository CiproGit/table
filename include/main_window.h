#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Main_window : public QMainWindow {
	Q_OBJECT

private:
	Ui::Main_window *ui;
	QTableWidget *table;

public:
	Main_window(QWidget *parent = nullptr);
	~Main_window();

public slots:
	void on_create();
};
#endif // MAIN_WINDOW_H

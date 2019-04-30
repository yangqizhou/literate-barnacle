#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <fstream>
#include <QLabel>
#include <QPainter>
#include <QLine>

#include <string>
#include <iostream>
using namespace std;
using std::ifstream;

#define inf 999999
#define nmax 110


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    //写进文本编辑器
    void setText1();
    // 初始化边
    void init();
    // 计算最短路径
    void minPath();
    int flag1 =0;
    // 保存边
    void save();
    //增加一个点
    void addVertex();
    //插入name 获取自动生成的id  返回到添加点与点 信息页面
    void insert_name();
    //
    void endinsert();

    // 全局变量初始化
    void dataInit();

    void showAllVerter();

    //查询路劲
    void get();

    // 打印路径
    void print_path(int i,int j);
private:
    QString filePath;
    //
    QPushButton p1;
    //初始化按钮
    QPushButton p2;
    //运算按钮
    QPushButton p3;
    //结束添加按钮
    QPushButton p4; //
    //save按钮
    QPushButton p5; //
    //查看全部点信息按钮
    QPushButton p6; //
    //点击进行查询
    QPushButton p7; //

    //初始化提示函文本编辑器
    QLineEdit q1;
    //行文本编辑器
    QLineEdit q2;
    //行文本编辑器
    QLineEdit q3;
    //行文本编辑器
    QLineEdit q4;
    //标签设置
    QLabel l1;  //你输入姓名生成id
    //标签设置
    QLabel l2;
    //标签设置
    QLabel l3;
    //标签设置
    QLabel l4;
    //标签设置
    QLabel l5;  //请输入两点之间的path
    //坐标查询标签设置
    QLabel l6;  //请输入起始坐标id 和 终点坐标id 进行查询

    //start name 标签设置
    QLabel l9;

    //end name 标签设置
    QLabel l10;

    //path 标签设置
    QLabel l11;

    //坐标start id查询标签设置
    QLabel l7;

    //坐标end id查询标签设置
    QLabel l8;

    //QLineEdit文本编辑器
    QLineEdit t1;
    //QLineEdit文本编辑器
    QLineEdit t2;
    //QLineEdit文本编辑器
    QLineEdit t3;
    //QLineEdit文本编辑器
    QLineEdit t4;
    //QLineEdit文本编辑器
    QLineEdit t5;
    //QLineEdit文本编辑器
    QLineEdit t6;
//
    //QLineEdit文本编辑器
    QLineEdit t7;
    //QLineEdit文本编辑器
    QLineEdit t8;

    //QLineEdit文本编辑器
    QLineEdit t9;  //start name

    //QLineEdit文本编辑器
    QLineEdit t10;  //箭头

    //QLineEdit文本编辑器
    QLineEdit t11; // end name

    //QLineEdit文本编辑器
    QLineEdit t12; // path

    //QLineEdit文本编辑器 作为分割线1
    QLineEdit L1;    //
    //QLineEdit文本编辑器 作为分割线2
    QLineEdit L2;    //
    //QLineEdit文本编辑器 作为分割线3
    QLineEdit L3;    //

    //查看所有点信息TextEdit text1
    QTextEdit text1;

    //查看目标id信息  TextEdit text2
    QTextEdit text2;

    //结构体
    struct vertex
    {
        // 点编号1~n
        int id;
        // 该点名字, 例如（贵师大等等）
        string name;
    } V[nmax];

    //文件操作流定义
    ifstream fin;
    ofstream fout;
    int n,m, edge[nmax][nmax], path[nmax][nmax], value[nmax][nmax];
};

#endif // WIDGET_H

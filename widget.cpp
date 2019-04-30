#include "widget.h"

#include <QTextEdit>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <QPainter>
#include <string>
#include <stack>
#include <QDir>

extern int n, m, edge[nmax][nmax], path[nmax][nmax], value[nmax][nmax];

using namespace std;
using std::ifstream;

Widget::Widget(QWidget *parent) : QWidget(parent)
{

    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    qDebug()<<"path"<<currentPath;
    QDir temDir("../test07/");
    QString newfilePath = temDir.absolutePath();
    filePath = newfilePath;
    qDebug()<<filePath<<endl;

    //��ʼ��
    Widget::dataInit();
    Widget::init();


    this->resize(1000,600);
    this->setFixedSize(1000,600);
    //�����ӱ���Ϣ�İ�ť
    p1.setText(QStringLiteral("ȷ�����"));
    p1.setParent(this);
    p1.move(500,100);
    p1.resize(100,30);


    //������Ӱ�ť
    p4.setText(QStringLiteral("�������"));
    p4.setParent(this);
    p4.move(620,100);
    p4.resize(100,30);
    //��ӱ���Ϣ�ı�ǩ
    l1.setParent(this);
    l1.setText(QStringLiteral("startλ�ñ��"));
    l1.move(10,80);

    //��������start��Ϣ���ı��༭��
    t1.setParent(this);
    t1.resize(120,30);
    t1.move(10,100);

    //��ӱ���Ϣ�ı�ǩ
    l2.setParent(this);
    l2.setText(QStringLiteral("endλ�ñ��"));
    l2.move(150,80);

    //��������end��Ϣ���ı��༭��
    t2.setParent(this);
    t2.resize(120,30);
    t2.move(150,100);

    //��ӱ���Ϣ�ı�ǩ
    l3.setParent(this);
    l3.setText(QStringLiteral("����"));
    l3.move(310,80);

    //��ӵ���Ϣ�ı�ǩ
    l4.setParent(this);
    l4.setText(QStringLiteral("λ������"));
    l4.move(10,10);

    //save��ť
    p5.setParent(this);
    p5.setText(QStringLiteral("����"));
    p5.move(10,200);
    p5.resize(220,30);

    q4.setParent(this);
    q4.resize(220,30);
    q4.setText(QStringLiteral("û�б���"));
    q4.setReadOnly(true);
    q4.move(500,200);
    q4.setStyleSheet("border:none;background-color:rgba(240,240,240);");

    //
    t3.setParent(this);
    t3.resize(120,30);
    t3.move(310,100);

    //
    t4.setParent(this);
    t4.setText(QStringLiteral("û�в���"));
    t4.move(800,100);
    t4.resize(200,30);
    t4.setReadOnly(true);
    t4.setStyleSheet("border:none;background-color:rgba(240,240,240);");
    //������ӵ㰴ť
    p2.setParent(this);
    p2.setText(QStringLiteral("ȷ��"));
    p2.move(500,30);
    p2.resize(220,30);

    //insert name��ʾ��
    q1.setParent(this);
    q1.resize(300,30);
    q1.move(10,30);

    //
    L1.setParent(this);
    L1.setStyleSheet("background-color:rgb(64,66,68);border:none;");
    L1.setReadOnly(true);
    L1.resize(1200,5);
    L1.move(-10,70);

    //
    L2.setParent(this);
    L2.setStyleSheet("background-color:rgb(64,66,68);border:none;");
    L2.setReadOnly(true);
    L2.resize(1200,5);
    L2.move(-10,250);
    //�������㰴ť
    p3.setParent(this);
    p3.setText(QStringLiteral("����"));
    p3.move(10,150);
    p3.resize(220,30);

    q3.setParent(this);
    q3.resize(220,30);
    q3.setText(QStringLiteral("û������"));
    q3.setReadOnly(true);
    q3.move(500,150);
    q3.setStyleSheet("border:none;background-color:rgba(240,240,240);");
    //�鿴ȫ������Ϣ��ť
    p6.setParent(this);
    p6.resize(220,30);
    p6.setText(QStringLiteral("��ѯ"));
    p6.move(10,270);

    //�鿴���е���ϢTextEdit text1
    text1.setParent(this);
    text1.resize(280,250);
    text1.move(10,320);

    //QLineEdit�ı��༭�� ��Ϊ�ָ���3
    L3.setParent(this);
    L3.setStyleSheet("background-color:rgb(64,66,68);border:none;");
    L3.setReadOnly(true);
    L3.resize(5,1000);
    L3.move(300,255);

    //�����ѯ��ǩ
    l6.setParent(this);
    l6.setText(QStringLiteral("��������ʼ����id  ��  �յ�����id ���в�ѯ"));
    l6.resize(260,30);
    l6.move(320,270);

    //����start name��ǩ
    l9.setParent(this);
    l9.setText(QStringLiteral("start name"));
    l9.resize(100,30);
    l9.move(620,270);

    //����end name��ǩ
    l10.setParent(this);
    l10.setText(QStringLiteral("end name"));
    l10.resize(110,30);
    l10.move(820,270);

    t9.setParent(this);
    t9.resize(130,30);
    t9.move(600,300);

    t10.setParent(this);
    t10.resize(40,30);
    t10.move(736,300);
    t10.setText("----->");
    t10.setReadOnly(true);
    t10.setStyleSheet("font-size:20px;border:none;background-color:rgba(240,240,240);");

    t11.setParent(this);
    t11.resize(130,30);
    t11.move(780,300);

    t12.setParent(this);
    t12.resize(50,30);
    t12.move(940,300);
    //����path��ǩ
    l11.setParent(this);
    l11.setText(QStringLiteral("path"));
    l11.resize(60,30);
    l11.move(950,270);


    //����start id��ѯ��ǩ
    l7.setParent(this);
    l7.setText(QStringLiteral("start id :"));
    l7.resize(140,30);
    l7.move(320,320);

    //����start id��ѯ��ǩ
    t5.setParent(this);
    t5.resize(160,30);
    t5.move(420,320);

    //�����ѯ��ǩ
    l8.setParent(this);
    l8.setText(QStringLiteral("end   id :"));
    l8.resize(140,30);
    l8.move(320,380);

    //����start id��ѯ��ǩ
    t6.setParent(this);
    t6.resize(160,30);
    t6.move(420,380);


    //�鿴ȫ������Ϣ��ť
    p7.setParent(this);
    p7.resize(220,30);
    p7.setText(QStringLiteral("�����ѯ"));
    p7.move(340,440);

    text2.setParent(this);
    text2.resize(380,220);
    text2.move(600,350);
    //���ӳ�ʼ����ť
   //connect(&p2,&QPushButton::pressed,this,&Widget::init);

   //����insert��ť
  // connect(&p1,&QPushButton::pressed,this,&Widget::addVertex);

   //connect Calculation Button
   //connect(&p3,&QPushButton::pressed,this,&Widget::minPath);
    text1.setReadOnly(true);
    text2.setReadOnly(true);
t9.setReadOnly(true);
t11.setReadOnly(true);
t12.setReadOnly(true);
    connect(&p2,&QPushButton::pressed,this,&Widget::insert_name);

    connect(&p1,&QPushButton::pressed,this,&Widget::addVertex);

    connect(&p4,&QPushButton::pressed,this,&Widget::endinsert);

    connect(&p5,&QPushButton::pressed,this,&Widget::save);

    connect(&p6,&QPushButton::pressed,this,&Widget::showAllVerter);

    connect(&p7,&QPushButton::pressed,this,&Widget::get);

    connect(&p3,&QPushButton::pressed,this,&Widget::minPath);
}

void Widget::setText1(){

}


//����name ��ȡ�Զ����ɵ�id  ���ص���ӵ���� ��Ϣҳ��
void Widget::insert_name(){
    QString name = q1.text();
    if(name!=""){
        n++; // is name id
        qDebug()<<"n==="<<n<<endl;
        V[n].id=n;
        V[n].name=name.toStdString();
        for (int i = 1; i <= n; ++i)
            {
                edge[i][n] = edge[n][i] = inf;
            }
        edge[n][n] = 0;
        /****************************************/
        t1.setText(QString::number(n));  //
        t1.setReadOnly(true);

        q1.setText(name);
        q1.setReadOnly(true);

        qDebug()<<"q1--->insert name : "<<name<<endl<<"q1--->insert id :"<<n<<endl;

    }else{
        qDebug()<<QStringLiteral("q1�������nameΪ��")<<endl;
    }
}

//��ʼ����
void Widget::init(){
    string filename = filePath.toStdString();

    fin.open((filename+"/edge"), ios::in);
        fin >> n;
        qDebug()<<" 1 "<<n<<endl;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                fin >> edge[i][j];
            }
        fin.close();

        // ����λ����Ϣ
        fin.open((filename+"/vecter"), ios::in);


        for (int i = 1; i <= n; ++i)
        {
            fin >> V[i].id >> V[i].name;
        }
        fin.close();

        // ���ؼ���������
        fin.open((filename+"/value"), ios::in);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                fin >> value[i][j];
        fin.close();
        // ����·��
        fin.open((filename+"/path"), ios::in);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                fin >> path[i][j];
        fin.close();

        if(flag1==0){
             qDebug()<<QString("Successful initialization")<<endl;
             flag1=1;
        }
        else{
            qDebug()<<QString("initialization failed")<<endl;
        }
        if(n!=0){
            qDebug()<<QStringLiteral("��ȡ����n��Ϊ0�� ���г�ʼ������")<<"  "<<n<<endl;
        }else{
            qDebug()<<QStringLiteral("��ȡ����nΪ0�� û�г�ʼ������")<<"  "<<n<<endl;
        }
        Widget::showAllVerter();
}

// �������·��
void Widget::minPath()
{

    // ���¼���value
        for (int i = 1; i <= n; ++i)
        {
            value[i][i] = edge[i][i] = 0;
            for (int j = 1; j <= n; ++j)
                value[i][j] = edge[i][j];
        }
        memset(path, -1, sizeof(path));
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (value[k][j] < inf && value[i][k] < inf && value[i][j] > value[i][k] + value[k][j])
                    {
                        value[i][j] = value[i][k] + value[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    qDebug()<<QStringLiteral("����ɹ� minPath")<<endl;
    q3.setText(QStringLiteral("���ݸ��� �Ѿ������µļ���"));
}

 //�����
void Widget::save(){
    string filename = filePath.toStdString();
    Widget::showAllVerter();
    // ����λ����Ϣ
    fout.open(filename+"/vecter", ios::out);
    for (int i = 1; i <= n; ++i)
    {
        fout << V[i].id << " " << V[i].name << endl;
    }
    fout.close();

    fout.open(filename+"/edge", ios::out);
    // �������
    fout << n << endl;
    // �����
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << edge[i][j] << " ";
        fout << endl;
    }
    fout.close();
    fout.open(filename+"/value", ios::out);
    // �����Լ���������
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << value[i][j] << " ";
        fout << endl;
    }
    fout.close();
    // ����·��
    fout.open(filename+"/path", ios::out);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << path[i][j] << " ";
        fout << endl;
    }
    fout.close();
    qDebug()<<QStringLiteral("save ����ɹ�")<<endl;
    q4.setText(QStringLiteral("�Ѿ������˱��棬ǧ��Ҫ�ظ�����"));
}

//����һ����
void Widget::addVertex()
{
    QString str = t1.text();
    int x,y,pa;
    try{ //conversion failure is 0
        x = t1.text().toInt();
        y = t2.text().toInt();
        pa = t3.text().toInt();

        t2.setText("ok");
        t3.setText("ok");
        t4.setText(QStringLiteral("�����ɹ�"));
    }catch (runtime_error){
        qDebug()<<"here error!"<<endl;
    }
     if(y==0&&pa==0){
     t2.setText(QStringLiteral("you input is 0 or not is number"));
     t2.setReadOnly(true);
     t3.setText(QStringLiteral("you input is 0 or not is number"));
     t3.setReadOnly(true);
     t4.setText("you operation is fail or you is end operation");
     q1.setReadOnly(false);
     qDebug()<<QStringLiteral("ȷ�����p1 ʧ��")<<x<<"  "<<y<<"   "<<y<<endl;
    }else{

    qDebug()<<QStringLiteral("ȷ�����p1 �ɹ�")<<x<<"  "<<y<<"   "<<y<<endl;
    int i, j;
    i=x;
    j=y;
    edge[i][j] = pa;
    edge[j][i] = edge[i][j];
  }
   minPath();
   Widget::showAllVerter();
}

void Widget::endinsert(){
    minPath();
    q1.setReadOnly(false);
}
void Widget::dataInit()
{
    n = 0;
    m = 0;
    memset(edge, inf, sizeof(edge));
    memset(path, -1, sizeof(path));
    memset(value, inf, sizeof(value));
}

void Widget::showAllVerter()
{
    QString str ="";
    for (int i = 1; i <= n; ++i)
    {
        //qDebug() << QStringLiteral(V[i].id) << " " << QStringLiteral(V[i].name)<<endl;
        qDebug()<<V[i].id<<"  "<<endl;
        qDebug()<<QString::fromStdString((V[i].name))  <<" "<<endl;
        str = str+  QString::number(V[i].id) +QStringLiteral(".   ")+ QString::fromStdString(V[i].name) + "\n";
    }
    text1.setText(str);
}


void Widget::get()
{
    int i=0,j=0;
    try{
        i = t5.text().toInt();
        j = t6.text().toInt();
    }catch(runtime_error){
        qDebug()<<"runtime_error!"<<endl;
    }
    t9.setText(QString::fromStdString(V[i].name));
    t11.setText(QString::fromStdString(V[j].name));
    t12.setText(QString::number(value[i][j]));
        print_path(i,j);
}

// ��ӡ·��
void Widget::print_path(int i,int j)
{
    QString str = "";

    if(i<=0||i>n||j<=0||j>n){
        str+=QString::fromStdString("Unknown number, please re-enter");
        qDebug()<<"two 0"<<endl;
    }else{
    int flag = 0;
    if (i > j)
    {
        flag = 1;
        swap(i, j);
    }
    stack<int> Q;
    while (true)
    {
        if (i == j)
        {
            str +=QString::fromStdString(V[i].name) +" --> "+QString::fromStdString(V[i].name);
            break;
        }
        // i->j���м���λ�ã��ҿ�ֱ��
        else if (path[i][j] == -1 && edge[i][i] != inf)
        {
            Q.push(j);
            Q.push(i);
            break;
        }
        // i->j�����ɵ���
        else if (path[i][j] == -1 && edge[i][i] == inf)
        {
            str +=QString::fromStdString(V[i].name) +" --> "+QString::fromStdString(V[i].name)+QString::fromStdString("�����ɵ���");
            qDebug()<<QString::fromStdString(V[i].name) << " --> " <<QString::fromStdString(V[j].name)<< "�����ɵ���" << endl;
        }
        // i->j֮�仹��λ��
        else if (path[i][j] != -1)
        {
            Q.push(j);
            j = path[i][j];
        }
    }
    // stackȥ����
    if (flag)
    {
        stack<int> temp;
        while (!Q.empty())
        {
            temp.push(Q.top());
            Q.pop();
        }
        Q.swap(temp);
    }
    // ��ӡλ��·��
    while (!Q.empty())
    {
        int index = Q.top();
        Q.pop();
        str+=QString::fromStdString(V[index].name);
        if (!Q.empty())
            str+=QString::fromStdString(" -->> ");
        else
        {
            str+=QString::fromStdString("\n");
        }
    }
  }
     text2.setText(str);
}

Widget::~Widget()
{
    Widget::save();
}

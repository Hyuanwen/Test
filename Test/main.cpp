#include "../osapi/osapi.h"
 
class Buddhist:public OS_Thread
{
private:
    virtual int Routine()
    {
        for (int i=0;!m_quitflag && i<100;i++)
        {
            printf("ma ni ma ni hong...\n");
            OS_Thread::Sleep(1);
        }
        printf("Exit!... \n");
        return 0;//正常退出
    }
public:    
    bool m_quitflag;
};


class Confucian:public OS_Thread
{
private:    
    virtual int Routine()
    {
        for (int i=0;i<500;i++)
        {
            printf("人之初，性本善 ...\n");
            OS_Thread::Sleep(1);
        }
        return 0;//正常退出
    }
};

int main()
{
    Buddhist task1;
    task1.m_quitflag=false;
    task1.Run();

    Confucian task2;
    task2.Run();
    getchar();
    //Join等待目标线程退出
    //回收这个进程的相关系统资源
    //注意Join不能回收自己
    task1.m_quitflag=true;
    OS_Thread::Join(&task1);
    return 0;
}
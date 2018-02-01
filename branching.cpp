void JUMP(char ch[])
{

    string TEST;
    TEST+=ch[0];
    TEST+=ch[1];
    TEST+=ch[2];
    TEST+=ch[3];

    for(int i=0;p[i].memloc!=END;i++)
        if(p[i].memloc==TEST)
        {
            index=i;
            return ;
        }

    cout<<"\n\n\t Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
    cout<<"\n\n\t Out Of Bound Memory Excess"<<endl;
}

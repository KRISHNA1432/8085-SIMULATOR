
void compile()
{
    string inst,op="",sub;
    char ch[1000];

    line=p[index].inst;
    locctr=p[index].memloc;

    istringstream iss(line);
    iss>>inst;

    while(iss>>sub)
        op+=sub;

    int i=0;

    while(op[i])
    {
        ch[i]=op[i];
        i++;
    }

    ch[i]='\0';

/*
        for(i=0;ch[i]!='\0';i++)
            if(!((ch[i]>='0'&&ch[i]<='9')||(ch[i]>='A'&&ch[i]<='F')||ch[i]==','))
            {
                cout<<"\n\n\t Error In Rvalue of Instruction At Memory Location "<<p[index].memloc<<" "<<ch[i]<<" "<<endl;
                index++;
                return ;
            }
*/
    if(inst=="SET")
        SET(ch);
    else if(inst=="MOV")
        MOV(ch);
    else if(inst=="MVI")
        MVI(ch);
    else if(inst=="LXI")
        LXI(ch);
    else if(inst=="LDA")
        LDA(ch);
    else if(inst=="STA")
        STA(ch);
    else if(inst=="LHLD")
        LHLD(ch);
    else if(inst=="SHLD")
        SHLD(ch);
    else if(inst=="STAX")
        STAX(ch);
    else if(inst=="XCHG")
        XCHG(ch);
    else if(inst=="CMP")
        CMP(ch);
    else if(inst=="CMA")
        CMA();
    else if(inst=="JUMP")
        JUMP(ch);
    else if(inst=="JNC")
        {
            if(CF==0)
                JUMP(ch);
        }
    else if(inst=="JC")
        {
            if(CF==1)
                JUMP(ch);
        }
    else if(inst=="JNZ")
        {
            if(ZF==0)
                JUMP(ch);
        }
    else if(inst=="JZ")
        {
            if(ZF==1)
                JUMP(ch);
        }
    else if(inst=="JP")
        {
            if(PF==1)
                JUMP(ch);
        }
    else if(inst=="JNP")
        {
            if(PF==0)
                JUMP(ch);
        }
    else if(inst=="ADD")
        ADD(ch);
    else if(inst=="ADI")
        ADI(ch);
    else if(inst=="SUB")
        SUB(ch);
    else if(inst=="INR")
        INR(ch);
    else if(inst=="DCR")
        DCR(ch);
    else if(inst=="INX")
        INX(ch);
    else if(inst=="DCX")
        DCX(ch);
    else if(inst=="DAD")
        DAD(ch);
    else if(inst=="SUI")
        SUI(ch);
    else if(inst=="HLT")
        return ;
    else
        cout<<"\n\n\t ERROR : Invalid Instruction Encountered"<<endl;

    updateflag();

}

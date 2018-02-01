void updateflag()
{
    char temp=A[0];

    if((A[0]>='7'&&A[0]<='9')||(A[0]>='A'&&A[0]<='F'))
        SF=1;
    else
        SF=0;

    if(temp!=A[0])
        AF=1;
    else
        AF=0;

    stringstream ss;
    ss << hex << A;
    unsigned n;
    ss >> n;
    bitset<8> b(n);

    int ct = 0;

    for(int i=0;i<8;i++)
        if(b[i])
            ct++ ;

    if(ct%2==0)
        PF=1;
    else
        PF=0;
}

int reverse(int x)
{
    int rtn = 0;
    do {
        int temp = rtn;
        rtn = rtn * 10 + x % 10;
        if ((rtn - x % 10) / 10 != temp)
            return 0;
        x = x / 10;
    } while (x != 0);

    return rtn;
}

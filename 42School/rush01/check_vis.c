

int check_line(int *line, int size)
{
    int i = 0;
    int count = 0;
    int max = 0;
    while(i < size)
    {
        if(line[i] > max)
        {
            max = line[i];
            count++;
        }
        i++;
    }
    return (count);
}

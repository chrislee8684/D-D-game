

char lowercase_string (char a[50])
{
    int i;
    for (i=0; i<strlen(a); i++)
    {
        a[i]=tolower(a[i]);
    }
    return *a;
}


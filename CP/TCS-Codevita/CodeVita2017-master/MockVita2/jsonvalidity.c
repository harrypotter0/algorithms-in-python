#include <stdio.h>
#include <stdlib.h>

#define EXPECT(x)               \
    if (ch != x)                \
    {                           \
        printf("-1");         \
        /*printf("%d", __LINE__);*/\
        exit(0);                \
    }

#define SCAN()                                      \
    if (scanf("%c", &ch))                           \
    {                                               \
        /*printf("Scanned %c at %d\n", ch, __LINE__);*/ \
    }

void parseObject();
void parseKeyValue();
void parseArray();

char ch;

int main()
{
    parseObject();
    printf("1");

    return 0;
}

void parseObject()
{
    SCAN();
    EXPECT('{');
    SCAN();
    if (ch != '}')
    {
        ungetc(ch, stdin);
        parseKeyValue();
    }
    EXPECT('}');
}

void parseKeyValue()
{
    SCAN();
    EXPECT(':');
    SCAN();
    if (ch == ',')
        return parseKeyValue();
    if (ch == '[')
    {
        ungetc(ch, stdin);
        return parseArray();
    }
    if (ch == '{')
    {
        ungetc(ch, stdin);
        return parseObject();
    }

    printf("-1");
    exit(0);
}

void parseArray()
{
    SCAN();
    EXPECT('[');
    SCAN();
    if (ch == ']')
        return;

    ungetc(ch, stdin);
    ch = ',';

    while (ch == ',')
    {
        parseObject();
        SCAN();
    }
    EXPECT(']');
    SCAN();
}

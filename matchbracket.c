#include <stdio.h>

#define MAX 100
#define TRUEVALUE TRUE
#define FALSEVALUE FALSE

struct stack {
    int top;
    char symbolStack[MAX];
};

void
initStack(struct stack *s)
{
    s->top = -1;
}

bool
isEmptySymbolStack(struct stack *s)
{
    bool status = false;
    if(s->top == -1) {
        status = true;
    } else {
        status = false;
    }

    return status;
}

int
pushSymbolToStack(struct stack *s, char symbol)
{
    if(s->top != MAX-1) {
        s->top++;
        s->symbolStack[s->top] = symbol;
        return 0;
    } else {
        printf("stack full\n");
    }
}

int 
popSymbolFromStack(struct stack *s)
{
    char symbol;
    if(s->top == -1) {
        printf("stack is empty\n");
        return -1;
    } else {
        symbol = s->symbolStack[s->top];
        s->top--;
    }
    return symbol;
}

bool
matchSymbol(char symbol, char stackSymbol)
{
    bool match = false;
    
    switch(symbol) {
        case ('}'):
            if(stackSymbol == '{') {
                match = true;
            }
        break;
        
        case (']'):
            if(stackSymbol == '[') {
                match = true;
            }
        break;
        
        case (')'):
            if(stackSymbol == '(') {
                match = true;
            }
        break;
        
        default:
            match = false;
        break;
    }
    
    return match;
}


int main() 
{

    stack s;
    int count = 0, index = 0;
    char symbol, lastSymbol, stackSymbol;
    bool valid = true;

    initStack(&s);

    printf("enter the no of symbols\n");
    scanf("%d", &count);

    index = count;
    do {
//    for(index = 0; index<=count; index++) {
        //printf("enter the %d th symbol\n", index);
        //printf("enter the symbol\n");
        //scanf("%c", &symbol);
        fflush(NULL);
        //fflush(stdin);
        symbol = getchar();
        if(symbol == '\n') {
            symbol = getchar();
        }
        fflush(NULL);
        //fflush(stdin);
        index--;
        //printf("entered character is %c\n", symbol);
        fflush(NULL);
        //fflush(stdin);

        if((symbol == '{')||(symbol == '(')||(symbol == '[')) {
            pushSymbolToStack(&s, symbol);
            lastSymbol = symbol;
        }

        if((symbol == '}')||(symbol == ')')||(symbol == ']')) {
            if(isEmptySymbolStack(&s)) {
                valid = false;
            } else {
                stackSymbol = popSymbolFromStack(&s);
                if(!matchSymbol) {
                    valid = false;
                }
            }
        }
    }while(index);

    if(!isEmptySymbolStack(&s)) {
        valid = false;
    }

    if(valid) {
        printf("properly terminated\n");
    } else {
        printf("improperly terminated\n");
    }

    return 0;
}

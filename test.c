#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

int add(int n,...)
{
  int ret=0;
  va_list p;
  va_start(p,n);
  while(n--)
  {
  ret += va_arg(p,int);
 }
  va_end(p);
  return ret;
}


void PrintInt(int n,int *count)
{
  if(n>10)
  PrintInt(n/10,count);

  putchar(n%10+48);
  (*count)++;
}


int myprintf(const char* format,...)
{
    int count=0;
    char last=0;
    va_list p;
    va_start(p,format);
    while(*format)
    {
      switch(*format)
      {
        case '%':
          {
            if(last=='%')
            {
              putchar('%');
            }
          }
          break;
        case 'c':
          if(last=='%')
          {
            putchar(va_arg(p,int ));
            count++;
          }
          else 
          {
            putchar(*format);
            count++;
          }
          break;
        case 's':
          if(last=='%')
          {
            char *str=va_arg(p,char*);
            puts(str);
            count+=strlen(str);
            
          }
          else 
          {
            putchar(*format);
            count++;
        }
          break;
        case 'd':
          if(last=='%')
          {
            PrintInt(va_arg(p,int),&count);
            //printf("|"); 
            //putchar(*format);
          }
          else 
          {
            putchar(*format);
            count++;
          }
          break;
          default :putchar(*format);count++;
                   break;
      }
      last=*format;
      format++;
    }
    return count;
}


int main()
{
  int count=0;
  count = myprintf("%d\n",19);
  printf("%d\n",count);
  count =myprintf("%s\n","nibi");
  printf("%d\n",count);
  count =printf("%c\n",'#');
  printf("%d\n",count);
  printf("2345678%d          231:%s      32%c  \n",123,"123",'&');
  count=printf("1\n");
  printf("print:%d\n ",count);
  //myprintf("my name is:%s  i am %d yes old  i like :%c\n","bit",14,"#");
  printf("%d\n",add(4,2,2,2,2));
  return 0;
}


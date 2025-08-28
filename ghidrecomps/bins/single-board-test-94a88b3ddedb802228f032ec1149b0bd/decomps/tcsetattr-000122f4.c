
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int tcsetattr(int __fd,int __optional_actions,termios *__termios_p)

{
  int iVar1;
  
  iVar1 = tcsetattr(__fd,__optional_actions,__termios_p);
  return iVar1;
}


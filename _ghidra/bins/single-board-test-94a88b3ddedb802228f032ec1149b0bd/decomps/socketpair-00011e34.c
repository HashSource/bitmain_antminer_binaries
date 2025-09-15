
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socketpair(int __domain,int __type,int __protocol,int *__fds)

{
  int iVar1;
  
  iVar1 = socketpair(__domain,__type,__protocol,__fds);
  return iVar1;
}


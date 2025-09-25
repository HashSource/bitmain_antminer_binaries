
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t openssl_get_fork_id(void)

{
  __pid_t _Var1;
  
  _Var1 = getpid();
  return _Var1;
}


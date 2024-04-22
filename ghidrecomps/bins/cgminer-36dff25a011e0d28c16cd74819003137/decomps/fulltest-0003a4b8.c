
_Bool fulltest(uchar *hash,uchar *target)

{
  uint uVar1;
  __uint32_t _Var2;
  __uint32_t _Var3;
  char *__ptr;
  char *__ptr_00;
  uchar *target_local;
  uchar *hash_local;
  uchar hash_swap [32];
  uchar target_swap [32];
  char tmp42 [2048];
  char *target_str;
  char *hash_str;
  uint32_t t32tmp;
  uint32_t h32tmp;
  uint32_t *target32;
  uint32_t *hash32;
  int i;
  _Bool rc;
  
  rc = true;
  i = 7;
  do {
    if (i < 0) {
LAB_0003a580:
      if (opt_debug != false) {
        swab256(hash_swap,hash);
        swab256(target_swap,target);
        __ptr = bin2hex(hash_swap,0x20);
        __ptr_00 = bin2hex(target_swap,0x20);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          if (rc == false) {
            uVar1 = 0xf154;
          }
          else {
            uVar1 = 0xf13c;
          }
          snprintf(tmp42,0x800," Proof: %s\nTarget: %s\nTrgVal? %s",__ptr,__ptr_00,uVar1 | 0x90000);
          _applog(7,tmp42,false);
        }
        free(__ptr);
        free(__ptr_00);
      }
      return rc;
    }
    _Var2 = __uint32_identity(*(__uint32_t *)(hash + i * 4));
    _Var3 = __uint32_identity(*(__uint32_t *)(target + i * 4));
    if (_Var3 < _Var2) {
      rc = false;
      goto LAB_0003a580;
    }
    if (_Var2 < _Var3) {
      rc = true;
      goto LAB_0003a580;
    }
    i = i + -1;
  } while( true );
}


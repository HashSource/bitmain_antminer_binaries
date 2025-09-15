
_Bool fulltest(uchar *hash,uchar *target)

{
  __uint32_t _Var1;
  __uint32_t _Var2;
  char *__ptr;
  char *__ptr_00;
  char *pcVar3;
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
LAB_0003e496:
      if (opt_debug != false) {
        swab256(hash_swap,hash);
        swab256(target_swap,target);
        __ptr = bin2hex(hash_swap,0x20);
        __ptr_00 = bin2hex(target_swap,0x20);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          if (rc == false) {
            pcVar3 = "no (false positive; hash > target)";
          }
          else {
            pcVar3 = "YES (hash <= target)";
          }
          snprintf(tmp42,0x800," Proof: %s\nTarget: %s\nTrgVal? %s",__ptr,__ptr_00,pcVar3);
          _applog(7,tmp42,false);
        }
        free(__ptr);
        free(__ptr_00);
      }
      return rc;
    }
    _Var1 = __uint32_identity(*(__uint32_t *)(hash + i * 4));
    _Var2 = __uint32_identity(*(__uint32_t *)(target + i * 4));
    if (_Var2 < _Var1) {
      rc = false;
      goto LAB_0003e496;
    }
    if (_Var1 < _Var2) {
      rc = true;
      goto LAB_0003e496;
    }
    i = i + -1;
  } while( true );
}


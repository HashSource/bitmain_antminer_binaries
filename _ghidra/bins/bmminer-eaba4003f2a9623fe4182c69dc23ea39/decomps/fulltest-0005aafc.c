
_Bool fulltest(uchar *hash,uchar *target)

{
  char *__ptr;
  char *__ptr_00;
  char *pcVar1;
  uchar *target_local;
  uchar *hash_local;
  uchar hash_swap [32];
  uchar target_swap [32];
  char tmp42 [2048];
  char *target_str;
  char *hash_str;
  uint t32tmp;
  uint h32tmp;
  uint *target32;
  uint *hash32;
  int i;
  _Bool rc;
  
  rc = true;
  i = 7;
  do {
    if (i < 0) {
LAB_0005ab88:
      if (opt_debug) {
        swab256(hash_swap,hash);
        swab256(target_swap,target);
        __ptr = bin2hex(hash_swap,0x20);
        __ptr_00 = bin2hex(target_swap,0x20);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          if (rc == false) {
            pcVar1 = "no (false positive; hash > target)";
          }
          else {
            pcVar1 = "YES (hash <= target)";
          }
          snprintf(tmp42,0x800," Proof: %s\nTarget: %s\nTrgVal? %s",__ptr,__ptr_00,pcVar1);
          _applog(7,tmp42,false);
        }
        free(__ptr);
        free(__ptr_00);
      }
      return rc;
    }
    if (*(uint *)(target + i * 4) < *(uint *)(hash + i * 4)) {
      rc = false;
      goto LAB_0005ab88;
    }
    if (*(uint *)(hash + i * 4) < *(uint *)(target + i * 4)) {
      rc = true;
      goto LAB_0005ab88;
    }
    i = i + -1;
  } while( true );
}


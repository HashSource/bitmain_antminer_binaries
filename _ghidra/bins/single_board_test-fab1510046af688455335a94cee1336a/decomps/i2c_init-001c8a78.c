
/* WARNING: Unknown calling convention */

int32_t i2c_init(int8_t *path2dev)

{
  clib_map *pMap;
  int32_t ret;
  i2c_value_t val;
  
  ret = -1;
  if (platform_inited == 0) {
    val.master._0_1_ = 'p';
    val.master._1_1_ = 'l';
    val.master._2_1_ = 'e';
    val.master._3_1_ = 'a';
    val.slave._0_1_ = 's';
    val.slave._1_1_ = 'e';
    val.slave._2_1_ = ' ';
    val.slave._3_1_ = 'i';
    _applog(0,(char *)&val,false);
    ret = -2;
  }
  else {
    pMap = i2c_ctx_map;
    if (i2c_index == 0) {
      pMap = new_c_map((clib_compare)0x1c89f9,(clib_destroy)0x0,(clib_destroy)0x0);
      i2c_ctx_map = pMap;
      pthread_mutex_init((pthread_mutex_t *)&i2c_mutex,(pthread_mutexattr_t *)0x0);
    }
    i2c_index = i2c_index + 1;
    val.master = 0;
    val.slave = 0;
    ret = i2c_index;
    insert_c_map(pMap,&ret,4,&val,8);
  }
  return ret;
}


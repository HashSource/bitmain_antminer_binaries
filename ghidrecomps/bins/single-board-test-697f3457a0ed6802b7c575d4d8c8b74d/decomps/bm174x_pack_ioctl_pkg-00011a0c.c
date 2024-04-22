
int bm174x_pack_ioctl_pkg(uint8_t *str,uint32_t str_len,uint32_t oper_type,void *param)

{
  int iVar1;
  void *param_local;
  uint32_t oper_type_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  uint8_t *work_str;
  uint8_t *address;
  base_type_t *item_1;
  base_type_t *item;
  
  switch(oper_type) {
  case 0:
                    /* WARNING: Load size is inaccurate */
    iVar1 = makeup_get_status_cmd
                      (str,str_len,*(uint8_t *)((int)param + 1),*param,*(uint8_t *)((int)param + 2))
    ;
    break;
  case 1:
                    /* WARNING: Load size is inaccurate */
    iVar1 = makeup_set_config_cmd
                      (str,str_len,*(uint8_t *)((int)param + 1),*param,*(uint8_t *)((int)param + 2),
                       *(uint32_t *)((int)param + 4));
    break;
  case 2:
    iVar1 = makeup_work_pkg(str,(uint8_t *)param);
    break;
  case 3:
                    /* WARNING: Load size is inaccurate */
    iVar1 = makeup_set_address_cmd(str,str_len,*param);
    break;
  case 4:
    iVar1 = makeup_chain_inactive_cmd(str,str_len);
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"unknow ioctl type %d\n",oper_type);
      _applog(0,tmp42,false);
    }
    iVar1 = 0;
  }
  return iVar1;
}


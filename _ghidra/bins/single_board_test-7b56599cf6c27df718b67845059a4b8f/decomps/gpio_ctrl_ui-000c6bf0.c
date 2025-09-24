
/* WARNING: Unknown calling convention */

int32_t gpio_ctrl_ui(ui_type_e type,ui_status_e status)

{
  clib_map *pMap;
  uint32_t uVar1;
  int iVar2;
  int32_t iVar3;
  uint32_t local_81c;
  filker_interval_t val;
  
  uVar1 = convert_ui_type_to_port(type);
  if (uVar1 == 0) {
    val.interval._0_1_ = 'u';
    val.interval._1_1_ = 'n';
    val.interval._2_1_ = 's';
    val.interval._3_1_ = 'u';
    val.timeout._0_1_ = 'p';
    val.timeout._1_1_ = 'o';
    val.timeout._2_1_ = 'r';
    val.timeout._3_1_ = 't';
    val.next_val._0_1_ = 'e';
    val.next_val._1_1_ = 'd';
    val.next_val._2_1_ = ' ';
    val.next_val._3_1_ = 'g';
    _applog(0,(char *)&val,false);
    iVar3 = -1;
  }
  else {
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
    pMap = ui_flicker_map;
    if (iVar2 == 0) {
      if (status == UI_OFF) {
        remove_port_form_gpio_map(uVar1,ui_flicker_map);
        iVar3 = gpio_write(uVar1,'\0');
      }
      else if (status == UI_ON) {
        remove_port_form_gpio_map(uVar1,ui_flicker_map);
        iVar3 = gpio_write(uVar1,'\x01');
      }
      else if (status == UI_FLICKER) {
        local_81c = uVar1;
        if ((ui_flicker_map == (clib_map *)0x0) ||
           (uVar1 = exists_c_map(ui_flicker_map,&local_81c), uVar1 != 0)) {
          iVar3 = -1;
        }
        else {
          val.interval = 200;
          iVar3 = -1;
          val.next_val = 1;
          val.timeout = uVar1;
          insert_c_map(pMap,&local_81c,4,&val,0xc);
        }
      }
      else {
        iVar3 = -2;
        val.interval._0_1_ = 'u';
        val.interval._1_1_ = 'n';
        val.interval._2_1_ = 's';
        val.interval._3_1_ = 'u';
        val.timeout._0_1_ = 'p';
        val.timeout._1_1_ = 'o';
        val.timeout._2_1_ = 'r';
        val.timeout._3_1_ = 't';
        val.next_val._0_1_ = 'e';
        val.next_val._1_1_ = 'd';
        val.next_val._2_1_ = ' ';
        val.next_val._3_1_ = 'l';
        _applog(0,(char *)&val,false);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
    }
    else {
      val.interval._0_1_ = 'f';
      val.interval._1_1_ = 'a';
      val.interval._2_1_ = 'i';
      val.interval._3_1_ = 'l';
      val.timeout._0_1_ = 'e';
      val.timeout._1_1_ = 'd';
      val.timeout._2_1_ = ' ';
      val.timeout._3_1_ = 't';
      val.next_val._0_1_ = 'o';
      val.next_val._1_1_ = ' ';
      val.next_val._2_1_ = 'a';
      val.next_val._3_1_ = 'p';
      _applog(0,(char *)&val,false);
      iVar3 = -1;
    }
  }
  return iVar3;
}


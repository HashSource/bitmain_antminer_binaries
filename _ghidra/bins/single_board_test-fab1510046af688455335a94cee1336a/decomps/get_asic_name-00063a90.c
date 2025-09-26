
uint16_t get_asic_name(char *asic_type)

{
  int iVar1;
  uint16_t uVar2;
  char *asic_type_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1398");
  if (iVar1 == 0) {
    uVar2 = 0x1398;
  }
  else {
    iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1360");
    if (iVar1 == 0) {
      uVar2 = 0x1360;
    }
    else {
      iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1362");
      if (iVar1 == 0) {
        uVar2 = 0x1362;
      }
      else {
        iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1399");
        if (iVar1 == 0) {
          uVar2 = 0x1399;
        }
        else {
          iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1366");
          if (iVar1 == 0) {
            uVar2 = 0x1366;
          }
          else {
            iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1368");
            if (iVar1 == 0) {
              uVar2 = 0x1368;
            }
            else {
              iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1370");
              if (iVar1 == 0) {
                uVar2 = 0x1370;
              }
              else {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Can\'t find Asic_Type: %s\n","get_asic_name",asic_type);
                snprintf(tmp1,0x800,"Can\'t find Asic_Type: %s",asic_type);
                log_to_file(tmp1,time_stamp);
                uVar2 = 0;
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}


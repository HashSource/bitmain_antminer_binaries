
/* WARNING: Unknown calling convention */

uint32_t calculate_hcn(void)

{
  uint32_t uVar1;
  uint uVar2;
  int iVar3;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t asic_hcn;
  uint32_t hcn;
  
  iVar3 = gAddress_interval << 0x18;
  uVar1 = calculate_core_number((Local_Config_Information->Hash_Board).Big_Core_Num);
  iVar3 = __aeabi_uidiv(iVar3,uVar1);
  uVar2 = (uint)(iVar3 * 0x14) / 100;
  uVar1 = __aeabi_uidiv(uVar2 * (Local_Config_Information->Test_Info).Test_Method.Midstate_Number,
                        (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : hcn = 0x%08x = %d, asic_hcn = 0x%08x = %d\n","calculate_hcn",uVar2,uVar2,uVar1,uVar1)
  ;
  snprintf(tmp1,0x100,"hcn = 0x%08x = %d, asic_hcn = 0x%08x = %d",uVar2,uVar2,uVar1,uVar1);
  log_to_file(tmp1,time_stamp);
  return uVar1;
}


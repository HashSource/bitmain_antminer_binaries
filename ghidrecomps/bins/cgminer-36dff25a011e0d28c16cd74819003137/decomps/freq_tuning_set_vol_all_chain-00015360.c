
/* WARNING: Variable defined which should be unmapped: sub_proj_index-local */

void freq_tuning_set_vol_all_chain(int sub_proj_index)

{
  int iVar1;
  double dVar2;
  undefined4 uStack_18;
  int sub_proj_index_local;
  double current_vol;
  
  dVar2 = get_current_voltage();
  iVar1 = (int)(longlong)
               ((double)(longlong)g_BHB91602_proj.conf_list[sub_proj_index].base_voltage -
               dVar2 * DAT_00015410);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (1 < iVar1) {
    set_working_voltage((double)CONCAT44(sub_proj_index,uStack_18));
    slowly_set_iic_power_to_working_voltage();
  }
  return;
}


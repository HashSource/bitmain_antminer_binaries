
void CMS_SharedInfo_encode(uchar **param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined *local_20;
  undefined4 local_1c;
  
  param_4 = param_4 << 3;
  local_20 = &local_38;
  local_35 = (undefined)param_4;
  local_2c = &local_28;
  local_28 = 4;
  local_24 = 4;
  local_38 = (undefined)((uint)param_4 >> 0x18);
  local_37 = (undefined)((uint)param_4 >> 0x10);
  local_36 = (undefined)((uint)param_4 >> 8);
  local_1c = 0;
  local_34 = param_2;
  local_30 = param_3;
  ASN1_item_i2d((ASN1_VALUE *)&local_34,param_1,(ASN1_ITEM *)&CMS_SharedInfo_it);
  return;
}


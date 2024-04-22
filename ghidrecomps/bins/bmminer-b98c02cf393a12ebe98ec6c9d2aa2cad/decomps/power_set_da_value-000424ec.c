
void power_set_da_value(short param_1)

{
  ushort uVar1;
  undefined4 local_38;
  undefined4 local_34;
  undefined auStack_30 [32];
  
  local_38 = DAT_00065c20;
  local_34 = DAT_00065c24;
  memset(auStack_30,0,0x20);
  uVar1 = (ushort)local_34._1_1_;
  local_34 = CONCAT31(local_34._1_3_,(char)param_1);
  local_34 = CONCAT22(uVar1 + (ushort)local_38._3_1_ + (ushort)local_38._2_1_ + param_1,
                      (undefined2)local_34);
  power_send_cmd(&local_38,8,auStack_30);
  return;
}


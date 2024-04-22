
/* WARNING: Unknown calling convention */

void AT24C02_save_offset_value(uchar which_iic,uchar which_chain,uchar *offset_value)

{
  undefined4 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  uVar1 = DAT_00024a90;
  printf("\n--- %s\n",DAT_00024a90);
  AT24C02_write_bytes(0x98,offset_value,which_iic,which_chain,8);
  pbVar2 = offset_value;
  do {
    pbVar3 = pbVar2 + 1;
    printf("%s: offset_value[%d] = %d\n",uVar1,(int)pbVar2 - (int)offset_value,(uint)*pbVar2);
    pbVar2 = pbVar3;
  } while (pbVar3 != offset_value + 8);
  return;
}


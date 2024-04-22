
int init_module(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  puVar1 = DAT_000101d4;
  printk(DAT_000101d8);
  iVar3 = alloc_chrdev_region(puVar1,0,1,DAT_000101dc,param_1,param_2);
  uVar5 = DAT_000101e0;
  if (iVar3 < 0) {
LAB_000100e8:
    printk(uVar5);
  }
  else {
    iVar3 = kmem_cache_alloc(*(undefined4 *)(DAT_000101e4 + 0x18),DAT_000101e8);
    puVar1[1] = iVar3;
    uVar5 = DAT_000101ec;
    if (iVar3 != 0) {
      cdev_init(iVar3,DAT_000101f0);
      iVar3 = puVar1[1];
      uVar5 = *puVar1;
      *(undefined4 *)(iVar3 + 0x24) = DAT_000101f4;
      iVar3 = cdev_add(iVar3,uVar5,1);
      uVar5 = DAT_000101f8;
      if (iVar3 != 0) goto LAB_000100e8;
      iVar3 = __request_region(DAT_000101fc,0x40000000,0x1400,DAT_00010200,0);
      puVar1[2] = iVar3;
      uVar5 = DAT_00010204;
      if (iVar3 != 0) {
        printk(DAT_00010208);
        iVar3 = ioremap(0x40000000,0x1400);
        puVar1[3] = iVar3;
        if (iVar3 == 0) {
          printk(DAT_0001020c,0);
          printk(DAT_00010210,puVar1[3]);
        }
        else {
          printk(DAT_00010214,iVar3);
          uVar5 = DAT_000101dc;
          puVar2 = DAT_000101d4;
          DataSynchronizationBarrier(0xf);
          printk(DAT_00010218,*(undefined4 *)puVar1[3]);
          uVar4 = __class_create(DAT_000101f4,uVar5,puVar2 + 4);
          puVar1[4] = uVar4;
          if (uVar4 < 0xfffff001) {
            device_create(uVar4,0,*puVar2,0,uVar5);
            return 0;
          }
          printk(DAT_0001021c);
        }
        return -1;
      }
    }
    printk(uVar5);
    iVar3 = 1;
  }
  return iVar3;
}



int init_module(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar2 = DAT_000101e8;
  puVar1 = DAT_000101e4;
  printk(DAT_000101ec);
  iVar5 = alloc_chrdev_region(puVar1,0,1,uVar2,param_1,param_2);
  if (iVar5 < 0) {
    printk(DAT_000101f0);
  }
  else {
    iVar5 = kmem_cache_alloc(*(undefined4 *)(DAT_000101f4 + 0x18),DAT_000101f8);
    puVar1[1] = iVar5;
    if (iVar5 == 0) {
      printk(DAT_000101fc);
      iVar5 = -10;
    }
    else {
      cdev_init(iVar5,DAT_00010200);
      uVar3 = DAT_00010204;
      iVar5 = puVar1[1];
      uVar7 = *puVar1;
      *(undefined4 *)(iVar5 + 0x24) = DAT_00010204;
      iVar5 = cdev_add(iVar5,uVar7,1);
      puVar4 = DAT_0001020c;
      if (iVar5 == 0) {
        iVar5 = __request_region(DAT_00010210,*DAT_0001020c,0x1000000,DAT_00010214,0);
        puVar1[2] = iVar5;
        if (iVar5 == 0) {
          printk(DAT_00010218);
          iVar5 = -0xc;
        }
        else {
          printk(DAT_0001021c);
          iVar5 = ioremap(*puVar4,0x1000000);
          puVar1[3] = iVar5;
          if (iVar5 == 0) {
            printk(DAT_00010220,0);
            printk(DAT_00010224,puVar1[3]);
            iVar5 = -0xd;
          }
          else {
            printk(DAT_00010228,iVar5);
            uVar6 = __class_create(uVar3,uVar2,puVar1 + 4);
            puVar1[4] = uVar6;
            if (uVar6 < 0xfffff001) {
              device_create(uVar6,0,*puVar1,0,uVar2);
              iVar5 = 0;
            }
            else {
              printk(DAT_0001022c);
              iVar5 = -0xe;
            }
          }
        }
      }
      else {
        printk(DAT_00010208);
        iVar5 = -0xb;
      }
    }
  }
  return iVar5;
}


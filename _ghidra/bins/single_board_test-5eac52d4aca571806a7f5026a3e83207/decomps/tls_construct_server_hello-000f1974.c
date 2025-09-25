
/* WARNING: Type propagation algorithm not settling */

undefined4 tls_construct_server_hello(int *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined1 uVar8;
  undefined1 auStack_1c [8];
  
  if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) {
LAB_000f19d2:
    uVar8 = param_1[0x113] == 1;
    if ((bool)uVar8) {
      iVar3 = 0x303;
      iVar5 = 0;
    }
    else {
      iVar3 = *param_1;
      iVar5 = iVar3 >> 0x1f;
    }
    iVar3 = WPACKET_put_bytes__(param_2,2,iVar3,iVar5,2);
  }
  else {
    iVar5 = *(int *)param_1[1];
    iVar3 = iVar5 + -0x10000;
    if (iVar3 != 0) {
      iVar3 = 1;
    }
    if (iVar5 < 0x304) {
      iVar3 = 0;
    }
    if (iVar3 == 0) goto LAB_000f19d2;
    uVar8 = true;
    iVar3 = WPACKET_put_bytes__(param_2,2,0x303,0,2);
  }
  if (iVar3 != 0) {
    if (param_1[0x113] == 1) {
      puVar1 = hrrrandom;
    }
    else {
      puVar1 = (undefined1 *)(param_1[0x1f] + 0x8c);
    }
    iVar3 = WPACKET_memcpy(param_2,puVar1,0x20);
    if (iVar3 != 0) {
      iVar3 = param_1[0x11d];
      if ((*(int *)(iVar3 + 0x198) == 0) &&
         ((*(int *)(param_1[0x134] + 0x24) << 0x1e < 0 || (param_1[0x23] != 0)))) {
        if ((bool)uVar8) {
LAB_000f1a82:
          uVar4 = param_1[0x12a];
          piVar2 = param_1 + 0x122;
          if (uVar4 < 0x21) {
            puVar7 = (undefined4 *)0x0;
            goto LAB_000f1a5c;
          }
        }
        else {
          uVar4 = *(uint *)(iVar3 + 0x148);
          if (uVar4 < 0x21) goto LAB_000f1a50;
        }
        uVar6 = 0x975;
      }
      else {
        *(undefined4 *)(iVar3 + 0x148) = 0;
        if ((bool)uVar8) goto LAB_000f1a82;
        uVar4 = 0;
LAB_000f1a50:
        piVar2 = (int *)(iVar3 + 0x14c);
        puVar7 = *(undefined4 **)(param_1[0x1f] + 0x240);
        if (puVar7 != (undefined4 *)0x0) {
          puVar7 = (undefined4 *)*puVar7;
        }
LAB_000f1a5c:
        iVar3 = WPACKET_sub_memcpy__(param_2,piVar2,uVar4,1);
        if (((iVar3 != 0) &&
            (iVar3 = (**(code **)(param_1[1] + 0x50))
                               (*(undefined4 *)(param_1[0x1f] + 0x210),param_2,auStack_1c),
            iVar3 != 0)) &&
           (iVar3 = WPACKET_put_bytes__(param_2,1,puVar7,(int)puVar7 >> 0x1f,1), iVar3 != 0)) {
          iVar3 = tls_construct_extensions(param_1,param_2);
          if (iVar3 == 0) {
            return 0;
          }
          if (param_1[0x113] == 1) {
            SSL_SESSION_free((SSL_SESSION *)param_1[0x11d]);
            param_1[0x11d] = 0;
            param_1[0x23] = 0;
            iVar3 = create_synthetic_message_hash(param_1,0,0,0,0);
            if (iVar3 != 0) {
              return 1;
            }
            return 0;
          }
          if ((param_1[299] & 1U) != 0) {
            return 1;
          }
          iVar3 = ssl3_digest_cached_records(param_1);
          if (iVar3 != 0) {
            return 1;
          }
          return 0;
        }
        uVar6 = 0x987;
      }
      goto LAB_000f19ba;
    }
  }
  uVar6 = 0x950;
LAB_000f19ba:
  ossl_statem_fatal(param_1,0x50,0x1eb,0x44,"ssl/statem/statem_srvr.c",uVar6);
  return 0;
}


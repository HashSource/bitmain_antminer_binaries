
undefined4 i2r_IPAddrBlocks(undefined4 param_1,undefined4 param_2,BIO *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar6 = 0;
  iVar2 = OPENSSL_sk_num(param_2);
  if (0 < iVar2) {
    do {
      puVar3 = (undefined4 *)OPENSSL_sk_value(param_2,iVar6);
      iVar2 = X509v3_addr_get_afi();
      if (iVar2 == 1) {
        BIO_printf(param_3,"%*sIPv4",param_4,"");
      }
      else if (iVar2 == 2) {
        BIO_printf(param_3,"%*sIPv6",param_4,"");
      }
      else {
        BIO_printf(param_3,"%*sUnknown AFI %u",param_4,"",iVar2);
      }
      if (2 < *(int *)*puVar3) {
        bVar1 = *(byte *)(((int *)*puVar3)[2] + 2);
        if (bVar1 == 4) {
          BIO_puts(param_3," (MPLS)");
        }
        else if (bVar1 < 5) {
          if (bVar1 == 2) {
            BIO_puts(param_3," (Multicast)");
          }
          else if (bVar1 < 3) {
            if (bVar1 != 1) goto LAB_0016c6ec;
            BIO_puts(param_3," (Unicast)");
          }
          else {
            BIO_puts(param_3," (Unicast/Multicast)");
          }
        }
        else if (bVar1 == 0x41) {
          BIO_puts(param_3," (VPLS)");
        }
        else if (bVar1 < 0x42) {
          if (bVar1 == 0x40) {
            BIO_puts(param_3," (Tunnel)");
          }
          else {
LAB_0016c6ec:
            BIO_printf(param_3," (Unknown SAFI %u)");
          }
        }
        else if (bVar1 == 0x42) {
          BIO_puts(param_3," (BGP MDT)");
        }
        else {
          if (bVar1 != 0x80) goto LAB_0016c6ec;
          BIO_puts(param_3," (MPLS-labeled VPN)");
        }
      }
      if (*(int *)puVar3[1] == 0) {
        BIO_puts(param_3,": inherit\n");
      }
      else if (*(int *)puVar3[1] == 1) {
        BIO_puts(param_3,":\n");
        iVar7 = 0;
        uVar8 = *(undefined4 *)(puVar3[1] + 4);
        while (iVar4 = OPENSSL_sk_num(uVar8), iVar7 < iVar4) {
          piVar5 = (int *)OPENSSL_sk_value(uVar8,iVar7);
          BIO_printf(param_3,"%*s",param_4 + 2,"");
          if (*piVar5 == 0) {
            iVar4 = i2r_address(param_3,iVar2,0,piVar5[1]);
            if (iVar4 == 0) {
              return 0;
            }
            iVar7 = iVar7 + 1;
            BIO_printf(param_3,"/%d\n",*(int *)piVar5[1] * 8 - (((int *)piVar5[1])[3] & 7U));
          }
          else {
            if (*piVar5 == 1) {
              iVar4 = i2r_address(param_3,iVar2,0,*(undefined4 *)piVar5[1]);
              if (iVar4 == 0) {
                return 0;
              }
              BIO_puts(param_3,"-");
              iVar4 = i2r_address(param_3,iVar2,0xff,*(undefined4 *)(piVar5[1] + 4));
              if (iVar4 == 0) {
                return 0;
              }
              BIO_puts(param_3,"\n");
            }
            iVar7 = iVar7 + 1;
          }
        }
      }
      iVar6 = iVar6 + 1;
      iVar2 = OPENSSL_sk_num(param_2);
    } while (iVar6 < iVar2);
  }
  return 1;
}


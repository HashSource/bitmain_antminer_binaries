
int check_asicnum(int asic_num,uchar nonce)

{
  byte bVar1;
  int iVar2;
  uchar nonce_local;
  int asic_num_local;
  
  switch(asic_num) {
  case 1:
    iVar2 = 1;
    break;
  case 2:
    if ((nonce & 0x80) == 0x80) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
    break;
  default:
    iVar2 = 0;
    break;
  case 4:
    bVar1 = nonce & 0xc0;
    if (bVar1 == 0x80) {
      iVar2 = 3;
    }
    else if (bVar1 == 0xc0) {
      iVar2 = 4;
    }
    else if (bVar1 == 0x40) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
    break;
  case 8:
    bVar1 = nonce & 0xe0;
    if (bVar1 == 0x80) {
      iVar2 = 5;
    }
    else {
      if (bVar1 < 0x81) {
        if (bVar1 == 0x40) {
          return 3;
        }
        if (bVar1 == 0x60) {
          return 4;
        }
        if (bVar1 == 0x20) {
          return 2;
        }
      }
      else {
        if (bVar1 == 0xc0) {
          return 7;
        }
        if (bVar1 == 0xe0) {
          return 8;
        }
        if (bVar1 == 0xa0) {
          return 6;
        }
      }
      iVar2 = 1;
    }
    break;
  case 0x10:
    bVar1 = nonce & 0xf0;
    if (bVar1 == 0x80) {
      iVar2 = 9;
    }
    else {
      if (bVar1 < 0x81) {
        if (bVar1 == 0x40) {
          return 5;
        }
        if (bVar1 < 0x41) {
          if (bVar1 == 0x20) {
            return 3;
          }
          if (bVar1 == 0x30) {
            return 4;
          }
          if (bVar1 == 0x10) {
            return 2;
          }
        }
        else {
          if (bVar1 == 0x60) {
            return 7;
          }
          if (bVar1 == 0x70) {
            return 8;
          }
          if (bVar1 == 0x50) {
            return 6;
          }
        }
      }
      else {
        if (bVar1 == 0xc0) {
          return 0xd;
        }
        if (bVar1 < 0xc1) {
          if (bVar1 == 0xa0) {
            return 0xb;
          }
          if (bVar1 == 0xb0) {
            return 0xc;
          }
          if (bVar1 == 0x90) {
            return 10;
          }
        }
        else {
          if (bVar1 == 0xe0) {
            return 0xf;
          }
          if (bVar1 == 0xf0) {
            return 0x10;
          }
          if (bVar1 == 0xd0) {
            return 0xe;
          }
        }
      }
      iVar2 = 1;
    }
    break;
  case 0x20:
    switch(nonce & 0xf8) {
    case 8:
      iVar2 = 2;
      break;
    case 0x10:
      iVar2 = 3;
      break;
    case 0x18:
      iVar2 = 4;
      break;
    case 0x20:
      iVar2 = 5;
      break;
    case 0x28:
      iVar2 = 6;
      break;
    case 0x30:
      iVar2 = 7;
      break;
    case 0x38:
      iVar2 = 8;
      break;
    case 0x40:
      iVar2 = 9;
      break;
    case 0x48:
      iVar2 = 10;
      break;
    case 0x50:
      iVar2 = 0xb;
      break;
    case 0x58:
      iVar2 = 0xc;
      break;
    case 0x60:
      iVar2 = 0xd;
      break;
    case 0x68:
      iVar2 = 0xe;
      break;
    case 0x70:
      iVar2 = 0xf;
      break;
    case 0x78:
      iVar2 = 0x10;
      break;
    case 0x80:
      iVar2 = 0x11;
      break;
    case 0x88:
      iVar2 = 0x12;
      break;
    case 0x90:
      iVar2 = 0x13;
      break;
    case 0x98:
      iVar2 = 0x14;
      break;
    case 0xa0:
      iVar2 = 0x15;
      break;
    case 0xa8:
      iVar2 = 0x16;
      break;
    case 0xb0:
      iVar2 = 0x17;
      break;
    case 0xb8:
      iVar2 = 0x18;
      break;
    case 0xc0:
      iVar2 = 0x19;
      break;
    case 200:
      iVar2 = 0x1a;
      break;
    case 0xd0:
      iVar2 = 0x1b;
      break;
    case 0xd8:
      iVar2 = 0x1c;
      break;
    case 0xe0:
      iVar2 = 0x1d;
      break;
    case 0xe8:
      iVar2 = 0x1e;
      break;
    case 0xf0:
      iVar2 = 0x1f;
      break;
    case 0xf8:
      iVar2 = 0x20;
      break;
    default:
      iVar2 = 1;
    }
    break;
  case 0x40:
    switch(nonce & 0xfc) {
    case 4:
      iVar2 = 2;
      break;
    case 8:
      iVar2 = 3;
      break;
    case 0xc:
      iVar2 = 4;
      break;
    case 0x10:
      iVar2 = 5;
      break;
    case 0x14:
      iVar2 = 6;
      break;
    case 0x18:
      iVar2 = 7;
      break;
    case 0x1c:
      iVar2 = 8;
      break;
    case 0x20:
      iVar2 = 9;
      break;
    case 0x24:
      iVar2 = 10;
      break;
    case 0x28:
      iVar2 = 0xb;
      break;
    case 0x2c:
      iVar2 = 0xc;
      break;
    case 0x30:
      iVar2 = 0xd;
      break;
    case 0x34:
      iVar2 = 0xe;
      break;
    case 0x38:
      iVar2 = 0xf;
      break;
    case 0x3c:
      iVar2 = 0x10;
      break;
    case 0x40:
      iVar2 = 0x11;
      break;
    case 0x44:
      iVar2 = 0x12;
      break;
    case 0x48:
      iVar2 = 0x13;
      break;
    case 0x4c:
      iVar2 = 0x14;
      break;
    case 0x50:
      iVar2 = 0x15;
      break;
    case 0x54:
      iVar2 = 0x16;
      break;
    case 0x58:
      iVar2 = 0x17;
      break;
    case 0x5c:
      iVar2 = 0x18;
      break;
    case 0x60:
      iVar2 = 0x19;
      break;
    case 100:
      iVar2 = 0x1a;
      break;
    case 0x68:
      iVar2 = 0x1b;
      break;
    case 0x6c:
      iVar2 = 0x1c;
      break;
    case 0x70:
      iVar2 = 0x1d;
      break;
    case 0x74:
      iVar2 = 0x1e;
      break;
    case 0x78:
      iVar2 = 0x1f;
      break;
    case 0x7c:
      iVar2 = 0x20;
      break;
    case 0x80:
      iVar2 = 0x21;
      break;
    case 0x84:
      iVar2 = 0x22;
      break;
    case 0x88:
      iVar2 = 0x23;
      break;
    case 0x8c:
      iVar2 = 0x24;
      break;
    case 0x90:
      iVar2 = 0x25;
      break;
    case 0x94:
      iVar2 = 0x26;
      break;
    case 0x98:
      iVar2 = 0x27;
      break;
    case 0x9c:
      iVar2 = 0x28;
      break;
    case 0xa0:
      iVar2 = 0x29;
      break;
    case 0xa4:
      iVar2 = 0x2a;
      break;
    case 0xa8:
      iVar2 = 0x2b;
      break;
    case 0xac:
      iVar2 = 0x2c;
      break;
    case 0xb0:
      iVar2 = 0x2d;
      break;
    case 0xb4:
      iVar2 = 0x2e;
      break;
    case 0xb8:
      iVar2 = 0x2f;
      break;
    case 0xbc:
      iVar2 = 0x30;
      break;
    case 0xc0:
      iVar2 = 0x31;
      break;
    case 0xc4:
      iVar2 = 0x32;
      break;
    case 200:
      iVar2 = 0x33;
      break;
    case 0xcc:
      iVar2 = 0x34;
      break;
    case 0xd0:
      iVar2 = 0x35;
      break;
    case 0xd4:
      iVar2 = 0x36;
      break;
    case 0xd8:
      iVar2 = 0x37;
      break;
    case 0xdc:
      iVar2 = 0x38;
      break;
    case 0xe0:
      iVar2 = 0x39;
      break;
    case 0xe4:
      iVar2 = 0x3a;
      break;
    case 0xe8:
      iVar2 = 0x3b;
      break;
    case 0xec:
      iVar2 = 0x3c;
      break;
    case 0xf0:
      iVar2 = 0x3d;
      break;
    case 0xf4:
      iVar2 = 0x3e;
      break;
    case 0xf8:
      iVar2 = 0x3f;
      break;
    case 0xfc:
      iVar2 = 0x40;
      break;
    default:
      iVar2 = 1;
    }
  }
  return iVar2;
}


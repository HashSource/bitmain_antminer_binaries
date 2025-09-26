
/* WARNING: Unknown calling convention */

double bitmain_convert_N_to_V_furmula(int32_t N)

{
  uint uVar1;
  double dVar2;
  
  switch(_g_power_state.power_version) {
  case 0x22:
    dVar2 = (1215.89444 - (double)(longlong)N) / 59.931507;
    break;
  default:
    dVar2 = -1.0;
    break;
  case 0x41:
  case 0x42:
    return (765.411764 - (double)(longlong)N) / 35.833333;
  case 0x43:
    dVar2 = (933.240365 - (double)(longlong)N) / 59.806034;
    break;
  case 0x61:
    dVar2 = (1144.502262 - (double)(longlong)N) / 52.243589;
    break;
  case 0x62:
  case 100:
  case 0x65:
  case 0x66:
    dVar2 = (double)(longlong)-N;
    break;
  case 0x71:
  case 0x72:
  case 0x75:
  case 0x77:
    dVar2 = (1190.935338 - (double)(longlong)N) / 78.742588;
    break;
  case 0x73:
  case 0x78:
    dVar2 = (1280.577821 - (double)(longlong)N) / 73.979365;
    break;
  case 0x74:
  case 0x76:
    dVar2 = (1156.107585 - (double)(longlong)N) / 76.090494;
    break;
  case 0xc1:
    uVar1 = _bitmain_get_power_fw_version(_g_power_state.power_fd);
    if ((uVar1 == 0x80000300) || ((uVar1 & 0xff) < 4)) {
      dVar2 = (double)(longlong)(0x4fb - N) / 85.0;
    }
    else {
      dVar2 = (1083.75 - (double)(longlong)N) / 70.83333333333;
    }
  }
  return dVar2;
}


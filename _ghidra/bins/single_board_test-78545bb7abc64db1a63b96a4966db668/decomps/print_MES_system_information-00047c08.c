
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_MES_system_information(void)

{
  Mes_System_Rule *Mes_System_Rule_ptr;
  Mes_System_Data *Mes_System_Data_ptr;
  Mes_System_Test_Config *Mes_System_Test_Config_ptr;
  Mes_System_Test_Loop *Mes_System_Test_Loop_ptr;
  Mes_System_Test_Method *Mes_System_Test_Method_ptr;
  Mes_System_Asic_Reg *Mes_System_Asic_Reg_ptr;
  Mes_System_Pattern *Mes_System_Pattern_ptr;
  Mes_System_Hw_Info *Mes_System_Hw_Info_ptr;
  Mes_System_Configs *Mes_System_Configs_ptr;
  size_t test_loop_id_array_index;
  size_t data_array_index;
  size_t test_config_array_index;
  size_t test_loop_array_index;
  size_t test_method_array_index;
  size_t asic_reg_array_index;
  size_t pattern_array_index;
  size_t power_version_array_index;
  size_t hw_info_array_index;
  size_t configs_array_index;
  
  for (Mes_System_Configs_ptr = (Mes_System_Config_File_Information->result).configs;
      Mes_System_Configs_ptr != (Mes_System_Configs *)0x0;
      Mes_System_Configs_ptr = Mes_System_Configs_ptr->next) {
    for (Mes_System_Hw_Info_ptr = Mes_System_Configs_ptr->hw_info;
        Mes_System_Hw_Info_ptr != (Mes_System_Hw_Info *)0x0;
        Mes_System_Hw_Info_ptr = Mes_System_Hw_Info_ptr->next) {
      for (power_version_array_index = 0; power_version_array_index < gPower_version_array_size;
          power_version_array_index = power_version_array_index + 1) {
      }
    }
    for (Mes_System_Pattern_ptr = (Mes_System_Configs_ptr->rule).pattern;
        Mes_System_Pattern_ptr != (Mes_System_Pattern *)0x0;
        Mes_System_Pattern_ptr = Mes_System_Pattern_ptr->next) {
    }
    for (Mes_System_Asic_Reg_ptr = (Mes_System_Configs_ptr->rule).asic_reg;
        Mes_System_Asic_Reg_ptr != (Mes_System_Asic_Reg *)0x0;
        Mes_System_Asic_Reg_ptr = Mes_System_Asic_Reg_ptr->next) {
    }
    for (Mes_System_Test_Method_ptr = (Mes_System_Configs_ptr->rule).test_method;
        Mes_System_Test_Method_ptr != (Mes_System_Test_Method *)0x0;
        Mes_System_Test_Method_ptr = Mes_System_Test_Method_ptr->next) {
    }
    for (Mes_System_Test_Loop_ptr = (Mes_System_Configs_ptr->rule).test_loop;
        Mes_System_Test_Loop_ptr != (Mes_System_Test_Loop *)0x0;
        Mes_System_Test_Loop_ptr = Mes_System_Test_Loop_ptr->next) {
    }
    for (Mes_System_Test_Config_ptr = Mes_System_Configs_ptr->test_config;
        Mes_System_Test_Config_ptr != (Mes_System_Test_Config *)0x0;
        Mes_System_Test_Config_ptr = Mes_System_Test_Config_ptr->next) {
      for (Mes_System_Data_ptr = Mes_System_Test_Config_ptr->data;
          Mes_System_Data_ptr != (Mes_System_Data *)0x0;
          Mes_System_Data_ptr = Mes_System_Data_ptr->next) {
        for (test_loop_id_array_index = 0; test_loop_id_array_index < gTest_loop_id_array_size;
            test_loop_id_array_index = test_loop_id_array_index + 1) {
        }
      }
    }
  }
  return;
}


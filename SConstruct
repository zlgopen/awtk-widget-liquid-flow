import os
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS)
helper.set_dll_def('src/liquid_flow.def').set_libs(['liquid_flow']).call(DefaultEnvironment)

SConscriptFiles = ['src/SConscript', 'demos/SConscript', 'tests/SConscript']
helper.SConscript(SConscriptFiles)

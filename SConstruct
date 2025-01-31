#!/usr/bin/env python

env = SConscript("./godot-cpp/SConstruct")

env.Append(CPPPATH=[
    "godot-cpp/include/",
    "godot-cpp/gen/include/",
    "src/"
])

sources = Glob("src/*.cpp")

library = env.SharedLibrary(
    "bin/car{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources
)

Default(library)

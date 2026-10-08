; One pair of retained images and one comparison per scene.

(rule
 (target ball.mincaml.ppm)
 (deps ball.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:ball.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target ball.ocamlc.ppm)
 (deps ball.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:ball.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff ball.ocamlc.ppm ball.mincaml.ppm)))

(rule
 (target contest.mincaml.ppm)
 (deps contest.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:contest.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target contest.ocamlc.ppm)
 (deps contest.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:contest.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff contest.ocamlc.ppm contest.mincaml.ppm)))

(rule
 (target cup.mincaml.ppm)
 (deps cup.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:cup.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target cup.ocamlc.ppm)
 (deps cup.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:cup.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff cup.ocamlc.ppm cup.mincaml.ppm)))

(rule
 (target dra.mincaml.ppm)
 (deps dra.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:dra.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target dra.ocamlc.ppm)
 (deps dra.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:dra.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff dra.ocamlc.ppm dra.mincaml.ppm)))

(rule
 (target lattice.mincaml.ppm)
 (deps lattice.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:lattice.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target lattice.ocamlc.ppm)
 (deps lattice.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:lattice.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff lattice.ocamlc.ppm lattice.mincaml.ppm)))

(rule
 (target mange.mincaml.ppm)
 (deps mange.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:mange.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target mange.ocamlc.ppm)
 (deps mange.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:mange.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff mange.ocamlc.ppm mange.mincaml.ppm)))

(rule
 (target mir.mincaml.ppm)
 (deps mir.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:mir.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target mir.ocamlc.ppm)
 (deps mir.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:mir.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff mir.ocamlc.ppm mir.mincaml.ppm)))

(rule
 (target orange.mincaml.ppm)
 (deps orange.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:orange.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target orange.ocamlc.ppm)
 (deps orange.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:orange.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff orange.ocamlc.ppm orange.mincaml.ppm)))

(rule
 (target piero1.mincaml.ppm)
 (deps piero1.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:piero1.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target piero1.ocamlc.ppm)
 (deps piero1.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:piero1.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff piero1.ocamlc.ppm piero1.mincaml.ppm)))

(rule
 (target piero2.mincaml.ppm)
 (deps piero2.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:piero2.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target piero2.ocamlc.ppm)
 (deps piero2.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:piero2.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff piero2.ocamlc.ppm piero2.mincaml.ppm)))

(rule
 (target planet.mincaml.ppm)
 (deps planet.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:planet.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target planet.ocamlc.ppm)
 (deps planet.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:planet.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff planet.ocamlc.ppm planet.mincaml.ppm)))

(rule
 (target shuttle.mincaml.ppm)
 (deps shuttle.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:shuttle.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target shuttle.ocamlc.ppm)
 (deps shuttle.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:shuttle.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff shuttle.ocamlc.ppm shuttle.mincaml.ppm)))

(rule
 (target test.mincaml.ppm)
 (deps test.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:test.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target test.ocamlc.ppm)
 (deps test.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:test.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff test.ocamlc.ppm test.mincaml.ppm)))

(rule
 (target test2.mincaml.ppm)
 (deps test2.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:test2.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target test2.ocamlc.ppm)
 (deps test2.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:test2.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff test2.ocamlc.ppm test2.mincaml.ppm)))

(rule
 (target test3.mincaml.ppm)
 (deps test3.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:test3.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target test3.ocamlc.ppm)
 (deps test3.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:test3.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff test3.ocamlc.ppm test3.mincaml.ppm)))

(rule
 (target tileball.mincaml.ppm)
 (deps tileball.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:tileball.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target tileball.ocamlc.ppm)
 (deps tileball.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:tileball.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff tileball.ocamlc.ppm tileball.mincaml.ppm)))

(rule
 (target tron.mincaml.ppm)
 (deps tron.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:tron.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target tron.ocamlc.ppm)
 (deps tron.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:tron.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff tron.ocamlc.ppm tron.mincaml.ppm)))

(rule
 (target tsu.mincaml.ppm)
 (deps tsu.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:tsu.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target tsu.ocamlc.ppm)
 (deps tsu.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:tsu.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff tsu.ocamlc.ppm tsu.mincaml.ppm)))

(rule
 (target tsu2.mincaml.ppm)
 (deps tsu2.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:tsu2.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target tsu2.ocamlc.ppm)
 (deps tsu2.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:tsu2.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff tsu2.ocamlc.ppm tsu2.mincaml.ppm)))

(rule
 (target tsu3.mincaml.ppm)
 (deps tsu3.sld min-rt.min-caml toolchain.sh)
 (action
  (with-stdin-from %{dep:tsu3.sld}
   (with-stdout-to %{target}
    (run bash %{dep:toolchain.sh} run
     %{env:MINCAML_TEST_RUNNER=} ./%{dep:min-rt.min-caml})))))

(rule
 (target tsu3.ocamlc.ppm)
 (deps tsu3.sld raytrace_reference.bc)
 (action
  (with-stdin-from %{dep:tsu3.sld}
   (with-stdout-to %{target}
    (run %{bin:ocamlrun} %{dep:raytrace_reference.bc})))))

(rule
 (alias min-rt-test)
 (action (diff tsu3.ocamlc.ppm tsu3.mincaml.ppm)))

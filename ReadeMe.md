Action 	Command
Configure	meson setup builddir
Build	meson compile -C builddir
Clean	meson compile --clean -C builddir
Change Options	meson configure builddir -Doption=value
Reconfigure	meson setup --reconfigure builddir

To reconfigure project include dir
meson  setup builddir --reconfigure
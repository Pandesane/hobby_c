project('hobby_c', 'c')

include_dir = include_directories('include')

pcre2_dep = dependency('libpcre2-8')
executable(
  'hobby_c',
  [
    'main.c',
    'src/data_structures/file_stream.c',
    'src/data_structures/dynamic_array.c',
    'src/data_structures/line.c',
    'src/data_structures/line_trimmer.c',
    'src/data_structures/do_stack.c',
    'src/data_structures/event_stack.c',
    'src/keywords.c',
    'src/string/libstring.c',
  ],
  dependencies: pcre2_dep,
  include_directories: include_dir,
)
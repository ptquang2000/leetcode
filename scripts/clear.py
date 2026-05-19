import os
import shutil

script_path = os.path.dirname(__file__)
work_path = os.path.join(script_path, '..')
test_path = os.path.join(work_path, 'test')

day_dirs = [dir_name for dir_name in os.listdir(work_path) if 'day' == dir_name[0:3]]
for day_dir in day_dirs:
    removed_dir = os.path.join(work_path, day_dir)
    shutil.rmtree(removed_dir)

test_init_file = os.path.join(test_path, "__init__.py")
if os.path.exists(test_init_file):
    os.remove(test_init_file)

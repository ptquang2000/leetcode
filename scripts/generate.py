import os
import dsa

script_path = os.path.dirname(__file__)
work_path = os.path.join(script_path, '..')
test_path = os.path.join(work_path, 'test')

day_dirs = [dir_name for dir_name in os.listdir(work_path) if 'day' == dir_name[0:3]]
today_dir = "day" + str(len(day_dirs) + 1)
try:
    today_path = os.path.join(work_path, today_dir)
    os.mkdir(today_path)
except FileExistsError:
    print(f"Directory '{today_dir}' has already existed")
    exit(1)

def generate_method(props):
    return_val = "return"
    if dsa.RETURN in props:
       if "None" in props[dsa.RETURN]:
           return_val = "return"
       elif props[dsa.RETURN] == "bool":
           return_val = "return False" 
       elif props[dsa.RETURN] == "int":
           return_val = "return 0"
       elif props[dsa.RETURN] == "str":
           return_val = "return \"\""
       elif props[dsa.RETURN].startswith("list"):
           return_val = "return []"
       elif props[dsa.RETURN].startswith("tuple"):
           return_val = "return ()"
       elif props[dsa.RETURN] == "ListNode":
           return_val = "return ListNode()"
       elif props[dsa.RETURN] == "BinaryNode":
           return_val = "return BinaryNode()"
       else:
           assert False, f"Unsupported return type: {props}"
    return_type = props[dsa.RETURN] if dsa.RETURN in props else "None"

    request_pkgs = ''
    if dsa.IMPORT in props:
        for pkg in props[dsa.IMPORT]:
            request_pkgs += f"{pkg}\n"

    return f'''{request_pkgs}

def {props[dsa.DEF]}({props[dsa.ARGS]}) -> {return_type}:
    {return_val}
    '''

def generate_class(props):
    content = f'''
class {props[dsa.DEF]}():
    def __init__(self) -> None:
    '''

    for member in props[dsa.PROPERTIES]:
        content += f'''
        self.{member[dsa.NAME]} = {member[dsa.VALUE]}
        '''

    content += f'''
        return
    '''

    if dsa.METHODS in props:
        for method in props[dsa.METHODS]:
            args = f", {method[dsa.ARGS]}" if len(method[dsa.ARGS]) else ''
            content += f'''
    def {method[dsa.DEF]}(self{args}):
        return
            '''
    return content


def add_import_pkg(pkg, att):
    return f'''
from {today_dir}.{pkg} import {att}
    '''

# NOTE: generate day{nth}/*.py
os.chdir(today_path)
for module, props in dsa.modules.items():
    module_path = os.path.join(today_path, f"{module}.py")
    with open(module_path, 'w') as f:
        if props[dsa.TYPE] == "function":
            f.write(generate_method(props))
        elif props[dsa.TYPE] == "class":
            f.write(generate_class(props))
    
# NOTE: generate test/__init__.py
os.chdir(test_path)
test_init_file = os.path.join(test_path, "__init__.py")
with open(test_init_file, 'w') as f:
    for module, props in dsa.modules.items():
        f.write(add_import_pkg(f"{module}", props[dsa.DEF]))

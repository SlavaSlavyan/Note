"""
task_manager.py
Рефакторинг приложения "Умный список дел" с применением структурного программирования
"""

def display_menu():
    """Отображение главного меню программы"""
    print("\n" + "="*50)
    print("          🎯 УМНЫЙ МЕНЕДЖЕР ЗАДАЧ")
    print("="*50)
    print("1. Добавить задачу")
    print("2. Показать все задачи")
    print("3. Показать задачи по категории")
    print("4. Отметить задачу как выполненную")
    print("5. Удалить задачу")
    print("6. Поиск задач")
    print("7. Показать статистику")
    print("8. Выйти")
    print("="*50)

def get_user_choice():
    """Получение и валидация выбора пользователя"""
    try:
        choice = input("Выберите действие (1-8): ").strip()
        if choice in ['1', '2', '3', '4', '5', '6', '7', '8']:
            return choice
        else:
            print("❌ Ошибка: выберите число от 1 до 8!")
            return None
    except Exception as e:
        print(f"❌ Ошибка ввода: {e}")
        return None

def get_task_input():
    """Получение данных о задаче от пользователя"""
    title = input("Введите название задачи: ").strip()
    if not title:
        print("❌ Название задачи не может быть пустым!")
        return None, None, None
    
    description = input("Введите описание задачи: ").strip()
    category = input("Введите категорию задачи: ").strip()
    
    if not category:
        category = "Без категории"
    
    return title, description, category

def add_task(tasks_list, categories_dict):
    """Добавление новой задачи в список"""
    title, description, category = get_task_input()
    
    if title is None:
        return False
    
    # Создание новой задачи
    new_task = {
        'id': len(tasks_list) + 1,
        'title': title,
        'description': description,
        'category': category,
        'completed': False
    }
    
    tasks_list.append(new_task)
    
    # Обновление статистики по категориям
    if category in categories_dict:
        categories_dict[category] += 1
    else:
        categories_dict[category] = 1
    
    print(f"✅ Задача '{title}' успешно добавлена в категорию '{category}'!")
    return True

def display_task(task):
    """Отображение одной задачи в читаемом формате"""
    status = "✅ Выполнена" if task['completed'] else "❌ Не выполнена"
    print(f"\n📋 Задача #{task['id']}")
    print(f"   Название: {task['title']}")
    print(f"   Описание: {task['description']}")
    print(f"   Категория: {task['category']}")
    print(f"   Статус: {status}")

def show_all_tasks(tasks_list):
    """Отображение всех задач"""
    if not tasks_list:
        print("📭 Список задач пуст!")
        return
    
    print(f"\n📋 ВСЕ ЗАДАЧИ (всего: {len(tasks_list)})")
    for task in tasks_list:
        display_task(task)

def show_tasks_by_category(tasks_list):
    """Отображение задач по выбранной категории"""
    if not tasks_list:
        print("📭 Список задач пуст!")
        return
    
    category = input("Введите категорию для поиска: ").strip()
    if not category:
        print("❌ Категория не может быть пустой!")
        return
    
    filtered_tasks = [task for task in tasks_list if task['category'].lower() == category.lower()]
    
    if not filtered_tasks:
        print(f"🔍 Задачи в категории '{category}' не найдены!")
        return
    
    print(f"\n📋 ЗАДАЧИ В КАТЕГОРИИ '{category}' (найдено: {len(filtered_tasks)})")
    for task in filtered_tasks:
        display_task(task)

def get_task_id_input():
    """Получение и валидация ID задачи"""
    try:
        task_id = int(input("Введите ID задачи: "))
        return task_id
    except ValueError:
        print("❌ Ошибка: ID должен быть числом!")
        return None

def find_task_by_id(tasks_list, task_id):
    """Поиск задачи по ID"""
    for task in tasks_list:
        if task['id'] == task_id:
            return task
    return None

def complete_task(tasks_list):
    """Отметка задачи как выполненной"""
    if not tasks_list:
        print("📭 Список задач пуст!")
        return False
    
    task_id = get_task_id_input()
    if task_id is None:
        return False
    
    task = find_task_by_id(tasks_list, task_id)
    
    if task:
        if task['completed']:
            print(f"ℹ️ Задача '{task['title']}' уже была выполнена!")
        else:
            task['completed'] = True
            print(f"✅ Задача '{task['title']}' отмечена как выполненная!")
        return True
    else:
        print(f"❌ Задача с ID {task_id} не найдена!")
        return False

def delete_task(tasks_list, categories_dict):
    """Удаление задачи из списка"""
    if not tasks_list:
        print("📭 Список задач пуст!")
        return False
    
    task_id = get_task_id_input()
    if task_id is None:
        return False
    
    for i, task in enumerate(tasks_list):
        if task['id'] == task_id:
            category = task['category']
            
            # Удаление задачи
            deleted_task = tasks_list.pop(i)
            
            # Обновление статистики категорий
            categories_dict[category] -= 1
            if categories_dict[category] == 0:
                del categories_dict[category]
            
            print(f"🗑️ Задача '{deleted_task['title']}' удалена!")
            return True
    
    print(f"❌ Задача с ID {task_id} не найдена!")
    return False

def search_tasks(tasks_list):
    """Поиск задач по ключевым словам"""
    if not tasks_list:
        print("📭 Список задач пуст!")
        return
    
    keyword = input("Введите ключевое слово для поиска: ").strip().lower()
    if not keyword:
        print("❌ Ключевое слово не может быть пустым!")
        return
    
    found_tasks = []
    for task in tasks_list:
        if (keyword in task['title'].lower() or 
            keyword in task['description'].lower() or 
            keyword in task['category'].lower()):
            found_tasks.append(task)
    
    if not found_tasks:
        print(f"🔍 Задачи по ключевому слову '{keyword}' не найдены!")
        return
    
    print(f"\n🔍 РЕЗУЛЬТАТЫ ПОИСКА ('{keyword}') (найдено: {len(found_tasks)})")
    for task in found_tasks:
        display_task(task)

def show_statistics(tasks_list, categories_dict):
    """Отображение статистики по задачам"""
    if not tasks_list:
        print("📭 Список задач пуст!")
        return
    
    total_tasks = len(tasks_list)
    completed_tasks = sum(1 for task in tasks_list if task['completed'])
    pending_tasks = total_tasks - completed_tasks
    
    print("\n📊 СТАТИСТИКА ЗАДАЧ")
    print(f"   Всего задач: {total_tasks}")
    print(f"   Выполнено: {completed_tasks} ({completed_tasks/total_tasks*100:.1f}%)")
    print(f"   Осталось: {pending_tasks} ({pending_tasks/total_tasks*100:.1f}%)")
    
    if categories_dict:
        print("\n📂 СТАТИСТИКА ПО КАТЕГОРИЯМ:")
        for category, count in categories_dict.items():
            category_tasks = [task for task in tasks_list if task['category'] == category]
            completed_in_category = sum(1 for task in category_tasks if task['completed'])
            print(f"   {category}: {count} задач ({completed_in_category} выполнено)")

def initialize_data():
    """Инициализация начальных данных"""
    return [], {}  # tasks, categories

def main():
    """Основная функция программы"""
    print("🎯 Добро пожаловать в УМНЫЙ МЕНЕДЖЕР ЗАДАЧ!")
    print("   Структурное программирование в действии!")
    
    # Инициализация данных
    tasks, categories = initialize_data()
    
    # Главный цикл программы
    while True:
        display_menu()
        choice = get_user_choice()
        
        if choice is None:
            continue
        
        if choice == '1':
            add_task(tasks, categories)
        elif choice == '2':
            show_all_tasks(tasks)
        elif choice == '3':
            show_tasks_by_category(tasks)
        elif choice == '4':
            complete_task(tasks)
        elif choice == '5':
            delete_task(tasks, categories)
        elif choice == '6':
            search_tasks(tasks)
        elif choice == '7':
            show_statistics(tasks, categories)
        elif choice == '8':
            print("\n👋 До свидания! Хорошего дня! 🎉")
            break

# Запуск программы
if __name__ == "__main__":
    main()
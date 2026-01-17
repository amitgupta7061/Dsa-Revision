# Laravel Todo App - Complete Guide

## 🚀 Commands Used to Create This Project

### 1. Install Prerequisites
```bash
# Install PHP and extensions
sudo apt install php php-cli php-mbstring php-xml php-curl php-zip php-sqlite3 unzip

# Install Composer (PHP package manager)
sudo apt install composer
```

### 2. Create Laravel Project
```bash
cd /path/to/todo
composer create-project laravel/laravel .
```
This creates all Laravel files in current folder.
x
### 3. Create Model, Migration & Controller
```bash
php artisan make:model Todo -mc
```
- `-m` = create migration
- `-c` = create controller
- This single command creates 3 files!

### 4. Run Migrations (Create Database Tables)
```bash
php artisan migrate
```

### 5. Start Development Server
```bash
php artisan serve
```
Opens at: **http://127.0.0.1:8000**

---

## 📁 Folder Structure Explained

```
todo/
├── app/                    # 🧠 MAIN APPLICATION CODE
│   ├── Http/
│   │   └── Controllers/    # Handle requests (TodoController.php)
│   └── Models/             # Database models (Todo.php)
│
├── config/                 # ⚙️ Configuration files (database, mail, etc.)
│
├── database/
│   ├── migrations/         # 📋 Database table definitions
│   └── database.sqlite     # 💾 SQLite database file
│
├── public/                 # 🌐 Web accessible files (entry point)
│   └── index.php           # All requests start here
│
├── resources/
│   └── views/              # 🎨 Blade templates (HTML)
│       ├── layouts/        # Layout templates
│       └── todos/          # Todo-specific views
│
├── routes/
│   └── web.php             # 🛤️ URL routes (what URL goes where)
│
├── storage/                # 📂 Logs, cache, uploaded files
│
├── vendor/                 # 📦 Dependencies (don't edit!)
│
├── .env                    # 🔐 Environment variables (DB credentials)
├── composer.json           # 📋 PHP dependencies list
└── artisan                 # 🔧 Laravel CLI tool
```

---

## 🔄 How Request Works (Flow)

```
User visits /todos
       ↓
routes/web.php → finds matching route
       ↓
TodoController@index → gets data from database
       ↓
Todo Model → queries database
       ↓
views/todos/index.blade.php → renders HTML
       ↓
User sees the page
```

---

## 📝 Files We Created/Modified

| File | Purpose |
|------|---------|
| `app/Models/Todo.php` | Defines Todo data structure |
| `app/Http/Controllers/TodoController.php` | Handles all todo actions (CRUD) |
| `database/migrations/..._create_todos_table.php` | Database table schema |
| `routes/web.php` | URL routing |
| `resources/views/layouts/app.blade.php` | Main layout template |
| `resources/views/todos/index.blade.php` | List todos page |
| `resources/views/todos/create.blade.php` | Add new todo form |
| `resources/views/todos/edit.blade.php` | Edit todo form |

---

## 🛠️ Useful Artisan Commands

```bash
# List all routes
php artisan route:list

# Create controller
php artisan make:controller NameController

# Create model with migration
php artisan make:model Name -m

# Create migration only
php artisan make:migration create_tablename_table

# Run migrations
php artisan migrate

# Rollback last migration
php artisan migrate:rollback

# Clear cache
php artisan cache:clear

# Start server
php artisan serve
```

---

## 📊 Database (SQLite)

We use **SQLite** (simple file-based database).

Location: `database/database.sqlite`

Configuration in `.env`:
```
DB_CONNECTION=sqlite
```

---

## 🔗 Available Routes

| Method | URL | Action |
|--------|-----|--------|
| GET | `/todos` | List all todos |
| GET | `/todos/create` | Show create form |
| POST | `/todos` | Save new todo |
| GET | `/todos/{id}/edit` | Show edit form |
| PUT | `/todos/{id}` | Update todo |
| PATCH | `/todos/{id}/toggle` | Toggle completed |
| DELETE | `/todos/{id}` | Delete todo |

---

## ❓ Common Questions

**Q: Where is the database?**
A: `database/database.sqlite`

**Q: How to add new field to Todo?**
A: Create migration: `php artisan make:migration add_field_to_todos_table`

**Q: How to reset database?**
A: `php artisan migrate:fresh` (deletes all data!)

**Q: Where to change port?**
A: `php artisan serve --port=3000`

---

## 🎯 Quick Start (For Next Time)

```bash
cd /path/to/todo
php artisan serve
# Open http://127.0.0.1:8000
```

That's it! Your app is running! 🚀

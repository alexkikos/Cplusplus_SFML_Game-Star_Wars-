


template <class T>
void CreateEnemi(T*& enemies_array, int amount, char** texture, int size_text, int h, int w)
{
	if (enemies_array == nullptr) 	enemies_array = new T[amount];//выдел€ю местто дл€ наших картинок - ранее загруженных в пам€ть текстур	
	for (int i = 0; i < amount; i++)
	{
		enemies_array[i].createship(texture, size_text);
		enemies_array[i].setposition(rand() % w - w / 12, rand() % h / 8);
	}
}




template <class T>
void AddShotToArray(T*& shapes, int& size, T bullet)
{
	if (shapes == nullptr)
	{
		shapes = new T[1];
		shapes[0] = bullet;
		size++;
		return;
	}
	T* tmp = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = shapes[i];
	}
	tmp[size] = bullet;
	delete[] shapes;
	shapes = tmp;
	size++;
}

template <class T>
void DestroyBullet(T*& bullet_all, int& index, int& size_bullet)
{
	if (size_bullet == 0) return;
 	T* temp = new T[size_bullet - 1];
	int count = 0;
	for (int i = 0; i < index; i++)
	{
		temp[count++] = bullet_all[i];
	}
	for (int i = index + 1; i < index; i++)
	{
		temp[count++] = bullet_all[i];
	}
	if (bullet_all != nullptr) delete[] bullet_all;
	bullet_all = temp;
	size_bullet--;
}


template <class T>
void CreateArr2D(T**& a, int row, int col)
{
	a = new T * [row];
	for (int i = 0; i < row; i++)
	{
		a[i] = new T[col];
	}
}
template <class T>
void AddRowArr2D2(T**& main_array, int& row, T* row_what_need_add)
{
	if (strlen(row_what_need_add) > 0)
	{
		T** p = new T * [row + 1];
		for (int i = 0; i < row; i++)
		{
			p[i] = main_array[i];
		}
		p[row] = row_what_need_add;
		delete[]main_array;
		main_array = p;
		row++;
	}
}


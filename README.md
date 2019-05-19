#Vector klasės experimentiniai tyrimai.
## 1 Tyrimas
### operator[]
```shell
	T& operator[](size_type i) {
		if ( i > size() || i < 0) throw std::out_of_range("exceeding size limit at operator[]");
		return data[i];
	}
```
Funkcija veikia patikrindama ar norimo pasiekti elemento eilės numeris nėra didesnis negu elementų skaičius konteineryje. Jei didesnis, išmeta out_of_range exception, jei ne, gražina norimą elementą.  
### at
```shell
	T& at(size_type pos)
	{
		if (size() <= pos || pos < 0) throw std::out_of_range("Incorrect position requested by function at");
		return data[pos];
	}
```
Veikimas labai panašus į operator[], vienintelis skirtumas - iškviečiama kaip konteinerio funkcija, o ne operatorius.  
### reserve
```shell
	void reserve(size_type new_cap)
	{
		if (new_cap > capacity())
		{
			iterator new_data = alloc.allocate(new_cap);
			iterator new_avail = std::uninitialized_copy(data, avail, new_data);
			uncreate();
			data = new_data;
			avail = new_avail;
			limit = data + new_cap;
		}
	}
```
Jeigu rezervuojamas vietų skaičius yra mažesnis nei dabartinis konteinerio skaičius, tai allocator'ius išskiria naują atmintį, nukopijuoja narius į naują atmintį, atlaisvina seną ir prilygina reikiamus iteratorius/rodykles naujiems adresams.  
### clear
```shell
	void clear()
	{
		iterator new_data = alloc.allocate(capacity());
		size_type cap = capacity();
		uncreate();
		limit = new_data + cap;
		data = avail = new_data;
	}
```
Išskiria atmintį išvalytam konteineriui, tuomet atlaisvina seną konteinerio atmintį ir prilygina reikiamus iteratorius reikiamiems adresams.  
### resize
``` shell
	void resize(size_type count, value_type value = T())
	{
		if (count < size())
		{
			size_type new_size = count;
			iterator new_data = alloc.allocate(new_size);
			iterator new_avail = std::uninitialized_copy(data, data + count, new_data);
			iterator new_limit = new_data + capacity();

			uncreate();

			data = new_data;
			avail = new_avail;
			limit =  new_limit;
		}
		else if (count > size())
		{
			size_type new_size = count;
			iterator new_data = alloc.allocate(new_size);
			iterator it = std::uninitialized_copy(data, avail, new_data);
			std::uninitialized_fill(it, new_data + new_size - 1, value);
			iterator new_avail = new_data + new_size;
			iterator new_limit;
			if (capacity() < new_avail - new_data)
			{
				new_limit = new_avail;
			}
			else
			{
				new_limit = new_data + capacity();
			}
			uncreate();

			data = new_data;
			avail = new_avail;
			limit = new_limit;
		}
	}
```
Pertvarko konteinerio naudojamą atmintį ir elementų skaičių pagal nurodytą kriterijų.  
## 2 Tyrimas
```shell
mano sukurto vector push_back veikimas:

10000 eiluciu failo apdorojimo laikas = 0.103347 s.
100000 eiluciu failo apdorojimo laikas = 0.231947 s.
1000000 eiluciu failo apdorojimo laikas = 2.23993 s.
10000000 eiluciu failo apdorojimo laikas = 23.6114 s.

std::vector push_back veikimas:

10000 eiluciu failo apdorojimo laikas = 0.0561407 s.
100000 eiluciu failo apdorojimo laikas = 0.32323 s.
1000000 eiluciu failo apdorojimo laikas = 3.1494 s.
10000000 eiluciu failo apdorojimo laikas = 33.274 s.
```
## 3 Tyrimas
```shell
mano sukurta vector realizacija perskirsto atmintį per 25 kartus kai dirba su 10000000 eilučių failu.  

std::vector realizacija perskirsto atmintį taip pat per 25 kartus kai dirba su 10000000 eilučių failu.
```
## 4 Tyrimas
Programos veikimo spartos palyginimai tarp std::vector ir vector realizacijų.  
```shell
mano sukurta vector realizacija:

10000 eiluciu failo apdorojimo laikas = 0.122706 s.
100000 eiluciu failo apdorojimo laikas = 0.73243 s.
1000000 eiluciu failo apdorojimo laikas = 8.24652 s.
10000000 eiluciu failo apdorojimo laikas = 91.0389 s.

std::vector realizacija:

10000 eiluciu failo apdorojimo laikas = 0.115603 s.
100000 eiluciu failo apdorojimo laikas = 0.779072 s.
1000000 eiluciu failo apdorojimo laikas = 8.56233 s.
10000000 eiluciu failo apdorojimo laikas = 91.0628 s.
```

Norint, kad mano vector veiktų 3 užduotyje, teko atsisakyti prieš tai naudotų std::vector::iterator, kuriuos naudojau skirstydamas studentus.  

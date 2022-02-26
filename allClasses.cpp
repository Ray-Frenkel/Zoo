#include "allClasses.h"
#pragma warning(disable:4996)
using namespace std;

Animal::Animal() :m_childCount(0), m_avgLifetime(0)
{
	this->m_color = new char[5];
	strcpy(this->m_color,"GRAY");

}

Animal::Animal(const char* color, int childs, float avgLifetime)
{
	this->m_color = new char[strlen(color) + 1];
	strcpy(this->m_color,color);
	this->m_childCount = childs;
	this->m_avgLifetime = avgLifetime;
}

Animal::Animal(ifstream& in_file)
{
	int len;
	in_file.read((char*)&len, sizeof(len));
	m_color = new char[len + 1];
	in_file.read(m_color, len);
	m_color[len] = '\0';
	in_file.read((char*)&m_childCount, sizeof(m_childCount));
	in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));



}

Animal::~Animal()
{
	delete[] m_color;
}
void Animal::saveType(ofstream& out) const
{
	int num = 1;
	out << num << endl;
}
void Animal::saveTypeBin(ofstream& out) const
{
		int num = 1;
		out.write((char*)&num, sizeof(num));
}
void Animal::Load(ifstream& in_file)//to load from txt file
{
	if (this->m_color) delete[] this->m_color;
	char temp[200];
	in_file >> temp;
	this->m_color = new char[strlen(temp) + 1];
	strcpy(m_color,temp);
	in_file >> m_childCount;
	in_file >> m_avgLifetime;

}

void Animal::Save(ofstream& out_file)
{
	//out_file << typeid(*this).name() + 6 << " ";
	out_file << m_color << endl;
	out_file << m_childCount << endl;
	out_file << m_avgLifetime << endl;

}

void Animal::SaveBin(ofstream& out_file)
{
	//const char* name = (typeid(*this).name() + 6);
	//int size = strlen(name) + 1;
	//out_file.write((const char*)&size, sizeof(size));
	//out_file.write(name, size);

    int size = strlen(m_color) + 1;
	out_file.write((const char*)&size, sizeof(size));
	out_file.write(m_color, size);

	out_file.write((const char*)&m_childCount, sizeof(m_childCount));
	out_file.write((const char*)&m_avgLifetime, sizeof(m_avgLifetime));

}

const char* Animal::GetColor() const
{
	return m_color;
}

int Animal::GetChildCount() const
{
	return m_childCount;
}

float Animal::GetLifetime() const
{
	return m_avgLifetime;
}


//---------------------------------------------------------------------

Mammals::Mammals() :Animal()
{
	m_pregnancyTime = 0;
	m_milkLiters = 0;
}

Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk) :
	Animal(color, childs, avgLifetime)
{
	m_pregnancyTime = preg;
	m_milkLiters = milk;

}

Mammals::Mammals(ifstream& in_file) :Animal(in_file)
{
	in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
	in_file.read((char*)&m_milkLiters, sizeof(m_milkLiters));
}
void Mammals::saveType(ofstream& out) const
{
	int num = 3;
	out << num << endl;
}
void Mammals::saveTypeBin(ofstream& out) const
{
	int num = 2;
	out.write((char*)&num, sizeof(num));
}
Mammals::~Mammals()
{

}

void Mammals::Load(ifstream& in_file)//to load from txt file
{
	Animal::Load(in_file);
	in_file >> m_pregnancyTime;
	in_file >> m_milkLiters;

}

void Mammals::SaveBin(ofstream& out_file)
{
	Animal::SaveBin(out_file);

	out_file.write((const char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
	out_file.write((const char*)&m_milkLiters, sizeof(m_milkLiters));

}
void Mammals::Save(ofstream& out_file)//to save to txt file
{
	Animal::Save(out_file);
	out_file << m_pregnancyTime << endl;
	out_file << m_milkLiters << endl;
}

float Mammals::GetPregnanceTime() const
{
	return m_pregnancyTime;
}

float Mammals::GetMilk() const
{
	return m_milkLiters;
}
//---------------------------------------------------------------------

Birds::Birds() :Animal()
{
	m_incubationTime = 0;
}

Birds::Birds(const char* color, int childs, float avgLifetime, float incubation) :
	Animal(color, childs, avgLifetime)
{
	m_incubationTime = incubation;
}

Birds::Birds(ifstream& in_file) :Animal(in_file)
{
	in_file.read((char*)&m_incubationTime, sizeof(m_incubationTime));
}

Birds::~Birds()
{
}
void Birds::Load(ifstream& in_file)//to load from txt file
{
	Animal::Load(in_file);
	in_file >> m_incubationTime;

}
void Birds::saveType(ofstream& out) const
{
	int num = 2;
	out << num << endl;
}
void Birds::saveTypeBin(ofstream& out) const
{
	int num = 2;
	out.write((char*)&num, sizeof(num));
}
void Birds::Save(ofstream& out_file)//to save to txt file
{
	Animal::Save(out_file);
	out_file << m_incubationTime << endl;
}

void Birds::SaveBin(ofstream& out_file)
{
	Animal::SaveBin(out_file);

	out_file.write((const char*)&m_incubationTime, sizeof(m_incubationTime));


}
float Birds::GetIncubationTime() const
{
	return m_incubationTime;
}



///--------------------------------------------------------
Fish::Fish() :Animal()
{
	m_finCount = 0;
	m_gillsCount = 0;

}

Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills) :
	Animal(color, childs, avgLifetime)
{
	m_finCount = fin;
	m_gillsCount = gills;

}

Fish::Fish(ifstream& in_file) :Animal(in_file)
{
	in_file.read((char*)&m_finCount, sizeof(m_finCount));
	in_file.read((char*)&m_gillsCount, sizeof(m_gillsCount));
}

Fish::~Fish()
{
}
void Fish::saveType(ofstream& out) const
{
	int num = 4;
	out << num << endl;
}
void Fish::saveTypeBin(ofstream& out) const
{
	int num = 4;
	out.write((char*)&num, sizeof(num));
}
void Fish::Load(ifstream& in_file)//to load from txt file
{
	Animal::Load(in_file);
	in_file >> m_finCount;
	in_file >> m_gillsCount;
}

void Fish::Save(ofstream& out_file)//to save to txt file
{
	Animal::Save(out_file);
	out_file << m_finCount << endl;
	out_file << m_gillsCount << endl;
}

void Fish::SaveBin(ofstream& out_file)
{
	Animal::SaveBin(out_file);

	out_file.write((const char*)&m_finCount, sizeof(m_finCount));
	out_file.write((const char*)&m_gillsCount, sizeof(m_gillsCount));

}
int Fish::GetFinCount() const
{
	return m_finCount;
}

int Fish::GetGillsCount() const
{
	return m_gillsCount;
}
//-----------------------------------------

Horse::Horse() :Mammals()
{
	m_type = nullptr;
}

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type) :
	Animal(color,childs, avgLifetime),Mammals(color, childs, avgLifetime, preg, milk)
{
	this->m_type = new char[strlen(type) + 1];
	strcpy(this->m_type,type);
}

Horse::Horse(ifstream& in_file): Animal(in_file),Mammals(in_file)
{
	int len;
	in_file.read((char*)&len, sizeof(len));
	m_type = new char[len + 1];
	in_file.read(m_type, len);
	m_type[len] = '\0';
}

Horse::~Horse()
{
	delete[] m_type;
}
void Horse::saveType(ofstream& out) const
{
	int num = 6;
	out << num << endl;
}
void Horse::saveTypeBin(ofstream& out) const
{
	int num = 6;
	out.write((char*)&num, sizeof(num));
}
void Horse::Load(ifstream& in_file)//to load from txt file
{
	Mammals::Load(in_file);
	char temp[200];
	in_file.getline(temp, sizeof(temp));
	in_file.getline(temp, sizeof(temp));
	m_type = new char[strlen(temp) + 1];
	strcpy(m_type, temp);
	/*
	char temp[200];
	in_file >> temp;
	m_type = new char[strlen(temp) + 1];
	strcpy_s(m_type, strlen(temp) + 1, temp);
	temp[200];
	in_file >> temp;
	m_type = new char[strlen(temp) + 1];
	strcpy_s(m_type, strlen(temp) + 1, temp);
	*/
}
void Horse::Save(ofstream& out_file)//to save to txt file
{
	Mammals::Save(out_file);
	out_file << m_type << endl;
}

void Horse::SaveBin(ofstream& out_file)
{
	Mammals::SaveBin(out_file);

	int size = strlen(m_type) + 1;
	out_file.write((const char*)&size, sizeof(size));
	out_file.write(m_type, size);

}
const char* Horse::GetType() const
{
	return m_type;
}
//----------------------------------------------------------------
Flamingo::Flamingo() :Birds()
{
	m_avgHeight = 0;
}
void Flamingo::saveType(ofstream& out) const
{
	int num = 5;
	out << num << endl;
}
void Flamingo::saveTypeBin(ofstream& out) const
{
	int num = 5;
	out.write((char*)&num, sizeof(num));
}
Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) :
	Birds(color, childs, avgLifetime, incubation)
{
	m_avgHeight = avgHeight;
}

Flamingo::Flamingo(ifstream& in_file) :Birds(in_file)
{
	in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));
}

Flamingo::~Flamingo()
{
}

void Flamingo::Load(ifstream& in_file)//to load from txt file
{
	Birds::Load(in_file);
	in_file >> m_avgHeight;
}
void Flamingo::Save(ofstream& out_file)//to save to txt file
{
	Birds::Save(out_file);
	out_file << m_avgHeight << endl;
}
void Flamingo::SaveBin(ofstream& out_file)
{
	Birds::SaveBin(out_file);

	out_file.write((const char*)&m_avgHeight, sizeof(m_avgHeight));

}

float Flamingo::GetHeight() const
{
	return m_avgHeight;
}
//-----------------------------------
MammalsFish::MammalsFish() :Fish()
{
	this->m_pregnancyTime = 0;
	this->m_milkLiters = 0;
}
void MammalsFish::saveType(ofstream& out) const
{
	int num = 7;
	out << num << endl;
}
void MammalsFish::saveTypeBin(ofstream& out) const
{
	int num = 7;
	out.write((char*)&num, sizeof(num));
}
MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills) :
	Fish(color, childs, avgLifetime, fin, gills)
{
	this->m_milkLiters = milk;
	this->m_pregnancyTime = preg;
}

MammalsFish::MammalsFish(ifstream& in_file) : Fish(in_file)
{
	in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
	in_file.read((char*)&m_milkLiters, sizeof(m_milkLiters));
}


MammalsFish::~MammalsFish()
{
}
void MammalsFish::Load(ifstream& in_file)//to load from txt file
{
	Fish::Load(in_file);
	in_file >> m_pregnancyTime;
	in_file >> m_milkLiters;
}

void MammalsFish::Save(ofstream& out_file)//to save to txt file
{
	Fish::Save(out_file);
	out_file << m_pregnancyTime << endl;
	out_file << m_milkLiters << endl;
}
void MammalsFish::SaveBin(ofstream& out_file)
{
	Fish::SaveBin(out_file);

	out_file.write((const char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
	out_file.write((const char*)&m_milkLiters, sizeof(m_milkLiters));

}

/// ---------------------------

GoldFish::GoldFish() :MammalsFish()
{
	m_avgWeight = 0;
	m_avgLength = 0;
}

GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) :
	Animal(color,childs,avgLifetime),MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
{
	this->m_avgLength = avgL;
	this->m_avgWeight = avgW;
}

GoldFish::GoldFish(ifstream& in_file) : Animal(in_file),MammalsFish(in_file)
{
	in_file.read((char*)&m_avgLength, sizeof(m_avgLength));
	in_file.read((char*)&m_avgWeight, sizeof(m_avgWeight));
}

GoldFish::~GoldFish()
{
}
void GoldFish::saveType(ofstream& out) const
{
	int num = 8;
	out << num << endl;
}
void GoldFish::saveTypeBin(ofstream& out) const
{
	int num = 8;
	out.write((char*)&num, sizeof(num));
}
void GoldFish::Load(ifstream& in_file)//to load from txt file
{
	MammalsFish::Load(in_file);
	in_file >> m_avgLength;
	in_file >> m_avgWeight;
}
void GoldFish::Save(ofstream& out_file)//to save to txt file
{
	MammalsFish::Save(out_file);
	out_file << m_avgLength << endl;
	out_file << m_avgWeight << endl;
}

void GoldFish::SaveBin(ofstream& out_file)
{
	MammalsFish::SaveBin(out_file);

	out_file.write((const char*)&m_avgLength, sizeof(m_avgLength));
	out_file.write((const char*)&m_avgWeight, sizeof(m_avgWeight));

}


float GoldFish::GetWeight() const
{
	return m_avgWeight;
}

float GoldFish::GetLength() const
{
	return m_avgLength;
}


/// -----------------------------------
Mermaid::Mermaid() :MammalsFish()
{
	m_firstName = nullptr;
	m_lastName = nullptr;

}

Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName) :
	Animal(color,childs,avgLifetime),MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
{
	this->m_firstName = new char[strlen(firstName) + 1];
	strcpy(this->m_firstName,firstName);
	this->m_lastName = new char[strlen(lastName) + 1];
	strcpy(this->m_lastName,lastName);
}
void Mermaid::saveType(ofstream& out) const
{
	int num = 9;
	out << num << endl;
}
void Mermaid::saveTypeBin(ofstream& out) const
{
	int num = 9;
	out.write((char*)&num, sizeof(num));
}
Mermaid::Mermaid(ifstream& in_file) : Animal(in_file),MammalsFish(in_file)
{
	int len1;
	in_file.read((char*)&len1, sizeof(len1));
	m_firstName = new char[len1 + 1];
	in_file.read(m_firstName, len1);
	m_firstName[len1] = '\0';

	int len2;
	in_file.read((char*)&len2, sizeof(len2));
	m_lastName = new char[len2 + 1];
	in_file.read(m_lastName, len2);
	m_lastName[len2] = '\0';


}

Mermaid::~Mermaid()
{
	delete[] m_firstName;
	delete[] m_lastName;
}

void Mermaid::Load(ifstream& in_file)//to load from txt file
{
	MammalsFish::Load(in_file);

	char temp[200];
	in_file >> temp;
	m_firstName = new char[strlen(temp) + 1];
	strcpy(m_firstName,temp);

	in_file >> temp;
	m_lastName = new char[strlen(temp) + 1];
	strcpy(m_lastName,temp);


}

void Mermaid::Save(ofstream& out_file)//to save to txt file
{
	MammalsFish::Save(out_file);
	out_file << m_firstName << endl;
	out_file << m_lastName << endl;
}
void Mermaid::SaveBin(ofstream& out_file)
{
	MammalsFish::SaveBin(out_file);

	int size = strlen(m_firstName) + 1;
	out_file.write((const char*)&size, sizeof(size));
	out_file.write(m_firstName, size);

	int size1 = strlen(m_lastName) + 1;
	out_file.write((const char*)&size1, sizeof(size1));
	out_file.write(m_lastName, size1);
}

const char* Mermaid::GetFirstName() const
{
	return m_firstName;
}

const char* Mermaid::GetLastName() const
{
	return m_lastName;
}

Zoo::Zoo()
{
	this->m_name = nullptr;
	this->m_address = nullptr;
	this->m_ticketPrice = 0;
	this->m_openHours = nullptr;
	this->m_closeHours = nullptr;
	this->m_numOfAnimals = 0;
	this->m_animals = nullptr;
}

Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)
{
	this->m_name = new char[strlen(name) + 1];
	strcpy(this->m_name,name);

	this->m_address = new char[strlen(address) + 1];
	strcpy(this->m_address,address);

	this->m_ticketPrice = ticket;

	this->m_openHours = new char[strlen(open) + 1];
	strcpy(this->m_openHours,open);

	this->m_closeHours = new char[strlen(close) + 1];
	strcpy(this->m_closeHours,close);

	this->m_numOfAnimals = 0;
	this->m_animals = nullptr;

}

Zoo::Zoo(ifstream& in_file)
{
	int len1;
	in_file.read((char*)&len1, sizeof(len1));
	m_name = new char[len1 + 1];
	in_file.read(m_name, len1);
	m_name[len1] = '\0';

	int len2;
	in_file.read((char*)&len2, sizeof(len2));
	m_address = new char[len2 + 1];
	in_file.read(m_address, len2);
	m_address[len2] = '\0';

	in_file.read((char*)&m_ticketPrice, sizeof(m_ticketPrice));

	int len3;
	in_file.read((char*)&len3, sizeof(len3));
	m_openHours = new char[len3 + 1];
	in_file.read(m_openHours, len3);
	m_openHours[len3] = '\0';

	int len4;
	in_file.read((char*)&len4, sizeof(len4));
	m_closeHours = new char[len4 + 1];
	in_file.read(m_closeHours, len4);
	m_closeHours[len4] = '\0';

	in_file.read((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));
	m_animals = new Animal * [m_numOfAnimals];
	int i;
	int num;
	for (i = 0; i < m_numOfAnimals; i++)
	{
		in_file.read((char*)&num, sizeof(num));
		if (num == 2)
			m_animals[i] = new Birds(in_file);
		else if (num == 3)
			m_animals[i] = new Mammals(in_file);
		else if (num == 4)
			m_animals[i] = new Fish(in_file);
		else if (num == 5)
			m_animals[i] = new Flamingo(in_file);
		else if (num == 6)
			m_animals[i] = new Horse(in_file);
		else if (num == 7)
			m_animals[i] = new MammalsFish(in_file);
		else if (num == 8)
			m_animals[i] = new GoldFish(in_file);
		else if (num == 9)
			m_animals[i] = new Mermaid(in_file);

		//in_file.read((char*)&m_animals[i], sizeof(m_animals[i]));
	}
}

Zoo::~Zoo()
{
	int i;
	delete[] m_name;
	delete[] m_address;
	delete[] m_openHours;
	delete[] m_closeHours;
	/*
	for (i = 0; i < this->m_numOfAnimals; i++)
	{
		delete m_animals[i];
	}
	*/
	delete[] m_animals;
}

const char* Zoo::GetName() const
{
	return m_name;
}

const char* Zoo::GetAddress() const
{
	return m_address;
}

float Zoo::GetTicketPrice() const
{
	return m_ticketPrice;
}

const char* Zoo::GetOpenHour() const
{
	return m_openHours;
}

const char* Zoo::GetCloseHour() const
{
	return m_closeHours;
}

int Zoo::GetNumOfAnimals() const
{
	return m_numOfAnimals;
}

Animal** Zoo::GetAnimals() const
{
	return m_animals;
}


void Zoo::AddAnimal(Animal* an)
{
	Animal** temp = new Animal * [this->m_numOfAnimals + 1];
	for (int i = 0; i < this->m_numOfAnimals; i++)
		temp[i] = this->m_animals[i];

	temp[m_numOfAnimals++] = an;
	this->m_animals = temp;
}

Zoo& Zoo::operator+(Animal* an)
{
	AddAnimal(an);
	return *this;
}
/*
Zoo Zoo::operator+(const Zoo& other) const {
	Zoo* temp = new Zoo(this->GetName(), this->GetAddress(), this->GetTicketPrice(), this->GetOpenHour(), this->GetCloseHour());

	int sum = this->GetNumOfAnimals() + other.GetNumOfAnimals();

	temp->m_numOfAnimals = 0;

	for (int i = 0; i < this->GetNumOfAnimals(); i++)
		temp->AddAnimal(this->GetAnimals()[i]);

	for (int i = this->GetNumOfAnimals(), j = 0; i < sum; i++, j++)
		temp->AddAnimal(other.GetAnimals()[j]);

	return *temp;
}//done
*/

Zoo Zoo::operator+(const Zoo& other) const
{
	//Zoo newZoo(m_name, this->m_address, this->m_openHours, this->m_closeHours, this->m_numOfAnimals);
	Zoo *newZoo = new Zoo[1];
	newZoo[0].m_name = new char[strlen(this->m_name) + 1];
	strcpy(newZoo[0].m_name, this->m_name);

	newZoo[0].m_address = new char[strlen(this->m_address) + 1];
	strcpy(newZoo[0].m_address,this->m_address);

	newZoo[0].m_openHours = new char[strlen(this->m_openHours) + 1];
	strcpy(newZoo[0].m_openHours, this->m_openHours);

	newZoo[0].m_closeHours = new char[strlen(this->m_closeHours) + 1];
	strcpy(newZoo[0].m_closeHours, this->m_closeHours);

	newZoo[0].m_ticketPrice = this->m_ticketPrice;
	newZoo[0].m_numOfAnimals = this->m_numOfAnimals + other.m_numOfAnimals;
	newZoo[0].m_animals = new Animal * [newZoo[0].m_numOfAnimals];

	for (int i = 0; i < this->m_numOfAnimals; i++)
		newZoo[0].m_animals[i] = this->m_animals[i];

	int index = this->m_numOfAnimals;
	for (int i = 0; i < other.m_numOfAnimals; i++)
	{

		if (typeid(*(other.m_animals[i])) == typeid(Animal))
		{
			Animal* a = dynamic_cast<Animal*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new Animal(*a);
			index++;
		}
		else if (typeid(*(other.m_animals[i])) == typeid(Birds))
		{
			Birds* b = dynamic_cast<Birds*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new Birds(*b);
			index++;
		}
		else if (typeid(*(other.m_animals[i])) == typeid(Mammals))
		{
			Mammals* m = dynamic_cast<Mammals*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new Mammals(*m);
			index++;
		}
		else if (typeid(*(other.m_animals[i])) == typeid(Fish))
		{
			Fish* m = dynamic_cast<Fish*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new Fish(*m);
			index++;
		}
		else if (typeid(*(other.m_animals[i])) == typeid(Flamingo))
		{
			Flamingo* f = dynamic_cast<Flamingo*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new Flamingo(*f);
			index++;
		}
		else if (typeid(*(other.m_animals[i])) == typeid(Horse))
		{
			Horse* h = dynamic_cast<Horse*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new Horse(*h);
			index++;
		}
		else if (typeid(*(other.m_animals[i])) == typeid(MammalsFish))
		{
			MammalsFish* mf = dynamic_cast<MammalsFish*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new MammalsFish(*mf);
			index++;
		}
		else if (typeid(*(other.m_animals[i])) == typeid(GoldFish))
		{
			GoldFish* gf = dynamic_cast<GoldFish*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new GoldFish(*gf);
			index++;
		}

		else if (typeid(*(other.m_animals[i])) == typeid(Mermaid))
		{
			Mermaid* mer = dynamic_cast<Mermaid*>(other.m_animals[i]);
			newZoo[0].m_animals[index] = new Mermaid(*mer);
			index++;
		}

	}
	return newZoo[0];
}
void Zoo::Save(ofstream& ofs) const
{
	ofs << m_name << endl;
	ofs << m_address << endl;
	ofs << m_ticketPrice << endl;
	ofs << m_openHours << endl;
	ofs << m_closeHours << endl;
	ofs << m_numOfAnimals << endl;
	for (int i = 0; i < m_numOfAnimals; ++i)
		m_animals[i]->Save(ofs);

}

void Zoo::Load(ifstream& ifs)
{
	int namelen, adresslen, openlen, closelen;

	ifs >> namelen;
	this->m_name = new char[namelen + 1];
	ifs.getline(this->m_name, namelen);
	this->m_name[namelen] = '\0';

	ifs >> adresslen;
	this->m_address = new char[adresslen + 1];
	ifs.getline(this->m_address, adresslen);
	this->m_address[adresslen] = '\0';

	ifs >> m_ticketPrice;

	ifs >> openlen;
	this->m_openHours = new char[openlen + 1];
	ifs >> this->m_openHours;
	this->m_openHours[openlen] = '\0';

	ifs >> closelen;
	this->m_closeHours = new char[closelen + 1];
	ifs >> this->m_closeHours;
	this->m_closeHours[closelen] = '\0';

	ifs >> m_numOfAnimals;

	m_animals = new Animal * [m_numOfAnimals];

	for (int i = 0; i < m_numOfAnimals; ++i)
	{
		m_animals[i]->Load(ifs);
	}

}

void Zoo::SaveBin(ofstream& ofs) const
{
	int size = strlen(m_name) + 1;
	ofs.write((const char*)&size, sizeof(size));
	ofs.write(m_name, size);

    size = strlen(m_address) + 1;
	ofs.write((const char*)&size, sizeof(size));
	ofs.write(m_address, size);
	ofs.write((const char*)&m_ticketPrice, sizeof(m_ticketPrice));

	size = strlen(m_openHours) + 1;
	ofs.write((const char*)&size, sizeof(size));
	ofs.write(m_openHours, size);

	size = strlen(m_closeHours) + 1;
	ofs.write((const char*)&size, sizeof(size));
	ofs.write(m_closeHours, size);

	ofs.write((const char*)&m_numOfAnimals, sizeof(m_numOfAnimals));

	for (int i = 0; i < m_numOfAnimals; ++i)
	{
		this->m_animals[i]->saveTypeBin(ofs);
		this->m_animals[i]->SaveBin(ofs);
	}

}

Zoo& Zoo::operator+=(Animal* an)
{
	AddAnimal(an);
	return *this;
}

ofstream& operator<<(ofstream& out, const Zoo& z)
{
	int i;
	out << z.m_name << endl;
	out << z.m_address << endl;
	out << z.m_ticketPrice << endl;
	out << z.m_openHours << endl;
	out << z.m_closeHours << endl;
	out << z.m_numOfAnimals << endl;
	for (i = 0; i < z.m_numOfAnimals; i++)
	{
		z.m_animals[i]->saveType(out);
		z.m_animals[i]->Save(out);
	}
	return out;
}

ifstream& operator>>(ifstream& in, Zoo& z)
{
	int i;
	int len;
	char temp[200];
	in.getline(temp, sizeof(temp));
	z.m_name = new char[strlen(temp) + 1];
	strcpy(z.m_name,temp);

	in.getline(temp, sizeof(temp));
	z.m_address = new char[strlen(temp) + 1];
	strcpy(z.m_address,temp);

	//in.getline(temp, sizeof(temp));

	in >> z.m_ticketPrice;

	in.getline(temp, sizeof(temp));

	in.getline(temp, sizeof(temp));
	z.m_openHours = new char[strlen(temp) + 1];
	strcpy(z.m_openHours,temp);

	in.getline(temp, sizeof(temp));
	z.m_closeHours = new char[strlen(temp) + 1];
	strcpy(z.m_closeHours,temp);

	in >> z.m_numOfAnimals;

	z.m_animals = new Animal * [z.m_numOfAnimals];
	int num;
	for (i = 0; i < z.m_numOfAnimals; i++)
	{
		in >> num;
		//if (num == 1)
			//z.m_animals[i] = new Animal;
		if (num == 2)
		 z.m_animals[i] = new Birds;
		else if (num == 3)
			z.m_animals[i] = new Mammals;
		else if (num == 4)
			z.m_animals[i] = new Fish;
		else if (num == 5)
			z.m_animals[i] = new Flamingo;
		else if (num == 6)
			z.m_animals[i] = new Horse;
		else if (num == 7)
			z.m_animals[i] = new MammalsFish;
		else if (num == 8)
			z.m_animals[i] = new GoldFish;
		else if (num == 9)
			z.m_animals[i] = new Mermaid;
		z.m_animals[i]->Load(in);
	}

	return in;
}

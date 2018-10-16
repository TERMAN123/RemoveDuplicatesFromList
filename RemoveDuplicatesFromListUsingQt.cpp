#include <QList>

template <typename T>
void removeDuplicates(QList<T>& list)
{
	QList<int> toBeRemoved;
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = i + 1; j < list.size(); j++)
		{
			if (list.at(i) == list.at(j))
			{
				if (!toBeRemoved.contains(j))
				{
					toBeRemoved.append(j);
				}
			}
		}
	}

	qSort(toBeRemoved);

	int offset{ 0 };
	while (toBeRemoved.size() > 0)
	{
		int index = toBeRemoved.takeFirst();

		list.removeAt(index - offset);

		offset++;
	}
}


int main()
{
	QList<int> myints = { 75,42,75,12,42,75,13 };
	removeDuplicates(myints);
	return 0;
}
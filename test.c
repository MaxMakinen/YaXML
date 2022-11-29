#include "yaxml.h"

void	print_node(t_xml_node *node, int depth)
{
	int	index = 0;
	int	d_index = 0;
	int	ai = 0;
	char	d[depth];

	while (d_index < depth)
	{
		d[d_index] = '\t';
		d_index++;
	}
	d[depth] = '\0';
//	printf("%sdepth : %d\n", d, depth);
	printf("%sTAG = %s data = %s\n", d, node->tag, node->data);
	if (node->attributes.size > 0)
		printf("%sattributes:\n", d);
	while (ai < node->attributes.size)
	{
		printf("%s   key = %s value = %s\n", d, node->attributes.list[ai].key, node->attributes.list[ai].value);
		ai++;
	}
	printf("%schildren: %d\n", d, node->children.size);
	while (index < node->children.size)
	{
		print_node(node->children.list[index], depth + 1);
		index++;
	}

}

int	main(void)
{
	t_xml_doc	doc;
	t_xml_node	*main_node;
	int	head = 0;
	int	nodes = 0;
	int	attr = 0;
	
	if (xml_doc_load(&doc, "test.xml"))
	{
		printf("XML Document (version=%s, encoding=%s)\n\n", doc.version, doc.encoding);

		main_node = xml_node_child(doc.head, 0);
//		printf("head children = %d\n", doc.head->children.size);
//		while (head < doc.head->children.size)
//		{
//			printf("	tag = %s data =%s\n", doc.head->children.list[head]->tag, doc.head->children.list[head]->data);
//			attr = 0;
//			while (attr < doc.head->children.list[head]->attributes.size)
//			{
//				printf("		attr: key = %s value = %s\n", doc.head->children.list[head]->attributes.list[attr].key, doc.head->children.list[head]->attributes.list[attr].key);
//				attr++;
//			}
//			head++;
//		}
//		printf("head children = %d\n", doc.head->children.size);
//		printf("tag = %s attr = %s\n\n", main_node->tag, main_node->attributes.list[0].value);
		print_node(doc.head, 0);

		return (0);
	}

}